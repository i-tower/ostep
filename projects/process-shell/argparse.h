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

typedef struct argslist {
    size_t len;
    size_t size;
    char** list;
}ArgsList;

typedef struct StringArena {
    uintptr_t offset;
    size_t size;
    StringArena* next; // If we need more memory
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
    arena->offset = offset;
    memcpy(ret, str, len);
    return ret;
}

void push_argslist(ArgsList* aL, char* token) 
{
    if (aL->len + 1 == aL->size) { 
        if((aL = realloc(aL, aL->size * 2)) == NULL) {
            fprintf(stderr, "ArgsList realloc failed\n");
            exit(1);
        }

        aL->size *= 2;
    }

    aL->list[aL->len] = token;
    aL->len++;
    aL->list[aL->len] = NULL;
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
// storing the token in token_buffer up to the size of buffer_size. The stored token
// always includes a null terminator. Crashes the program if token size exceeds buffer size
// If no token is found length returned is 0. Tokens are separated by whitespace
size_t arg_tokenize(char* token_buffer, const char* instr, size_t buffer_size)
{

    static const char* next_token_ptr;
    static const char* previous_str;

    if (instr != previous_str) {
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
    }
    
    memcpy(token_buffer, &next_token_ptr[begin], token_len);
    
    token_buffer[token_len] = '\0';

    next_token_ptr = &next_token_ptr[end];
    return token_len;
}

// this sucks argslist doesn't really "own" the strings im giving it here...
// I'm hiding a memory allocation in here that the main program cant free.
size_t arg_parser(ArgsList* dest, StringArena *arena, char* src) 
{
    char token_buffer[256];
    
    size_t token_length = 0;
    size_t count = 0;
    while ((token_length = arg_tokenize(token_buffer, src, 4096)) != 0) {
        push_argslist(dest, string_alloc(arena, token_buffer, token_length));
        count++;
    }

    return count;
}

#endif