#ifndef ARG_PARSE
#define ARG_PARSE

#include <ctype.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define UNUSED(x) (void)(x)

#define STR_ARENA_ALIGN 8
#define MAX_TOKEN_LENGTH 4096

typedef struct StringArena StringArena;

typedef struct StringList {
    size_t len;
    size_t size;
    char** list;
}StringList;

typedef struct StringArena {
    uintptr_t offset;
    size_t size;
    StringArena* next; // If we need more memory. UNUSED
    char* data;
} StringArena;


uintptr_t align_forward(uintptr_t ptr, size_t align) 
{
    uintptr_t p = ptr;
    uintptr_t a = (uintptr_t) align;
    uintptr_t mod = p & (a - 1);

    if (mod != 0 ) {
        p += a - mod;
    }

    return p;
}


void init_string_arena(StringArena* arena, char* backing_buffer, size_t backing_buffer_size) 
{
    arena->data = backing_buffer;
    arena->offset = 0;
    arena->size = backing_buffer_size;
    memset(arena->data, 0, backing_buffer_size);
}

void string_arena_reset(StringArena* a) 
{
    a->offset = 0;
}

// String alloc expects the length of the string including the null terminator
char* string_alloc(StringArena* arena, char* str, size_t len) 
{
    if (arena->offset + len >= arena->size) {
        // Initialize and link another arena
        fprintf(stderr, "Too much memory used for args\n");
        exit(1);
    }

    // align the offset
    uintptr_t current_ptr = (uintptr_t) arena->data + arena->offset;
    uintptr_t offset = align_forward(current_ptr, STR_ARENA_ALIGN);
    offset -= (uintptr_t) arena->data;

    char* ret = &arena->data[offset];
    arena->offset = offset + len;
    memcpy(ret, str, len);
    return ret;
}


// FIXME: Should I change this data structure to reallocate the whole thing on realloc and
// have all string lists live on the heap? That seem better
void push_stringlist(StringList* sl, char* token) 
{
    if (sl->len + 1 == sl->size) { 
        if((sl->list = realloc(sl->list, sl->size * 2)) == NULL) {
            fprintf(stderr, "ArgsList realloc failed\n");
            exit(1);
        }

        sl->size *= 2;
    }

    sl->list[sl->len] = token;
    sl->len++;
    sl->list[sl->len] = NULL;
}

void reset_stringlist(StringList* sl) 
{
    for (size_t i = 0; i < sl->len; ++i) {
        sl->list[i] = NULL;
    }
    sl->len = 0;
}

// char *arg_whitespace = " \t\n\r\f";
//int arg_parser(char** dest, char* src, size_t arg_max);



// typedef struct stringslice{ 
//     char* beginptr;
//     char* endptr;
// } StringSlice; 

// compare strings
// set prev_str to instr
//---prog-arg1-arg2
//   ^   ^
//   Beg |
//       end  -> set next token ptr to end
//            -> alloc(end - beg) **using stack buffer
//            -> memcpy begin to end
//            -> set end to '\0'

// Takes a pointer to a null terminated string and returns the length of the token found
// the length of the found token should include the null terminator hello
// storing the token in token_buffer up to the size of buffer_size. The stored token
// always includes a null terminator. Crashes the program if token size exceeds buffer size
// If no token is found length returned is 0. Tokens are separated by whitespace
size_t arg_tokenize(char* token_buffer, const char* instr, const size_t count, size_t buffer_size)
{

    static const char* next_token_ptr;
    static const char* previous_str;

    if (instr != previous_str || count == 0) {
        previous_str = instr;
        next_token_ptr = instr;
    }

    size_t begin = 0;
    size_t end = 0;
    int chr_found = 0;
    for (size_t i = 0; 1 ; ++i) {
        if (isspace(next_token_ptr[i]) || next_token_ptr[i] == '\0') {
            if (chr_found) {
                end = i;
                break;                                                            
            } else if (next_token_ptr[i] == '\0'){ 
                break;
                
            } else {
                continue;
            }
        } else {
            if(!chr_found) {
                chr_found = 1;
                begin = i;   
            }
        }
    }
    
    size_t token_len = end - begin;
    if (token_len > buffer_size) {
        fprintf(stderr, "Token length exceeds buffer size!\n");
        exit(1);
    } else if (token_len == 0) {
        return 0;
    }
    
    memcpy(token_buffer, &next_token_ptr[begin], token_len);
    
    token_buffer[token_len] = '\0';

    next_token_ptr = &next_token_ptr[end];
    // add 1 to include null terminator
    return token_len + 1;
}

// Parses args from a user input string. Returns the number of arguments. 
size_t arg_parser(StringList* dest, StringArena *arena, const char* src) 
{
    char token_buffer[256];
    
    size_t token_length = 0;
    size_t count = 0;
    // HACK: Adding parameter to arg_tokenize call to know if we are
    // calling it for the first time with this command
    while ((token_length = arg_tokenize(token_buffer, src, count, 4096)) != 0) {
        push_stringlist(dest, string_alloc(arena, token_buffer, token_length));
        count++;
    }

    return count;
}

#endif