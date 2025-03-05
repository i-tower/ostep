#ifndef ARG_PARSE
#define ARG_PARSE

#include <ctype.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNUSED(x) (void)(x)

// char *arg_whitespace = " \t\n\r\f";
int arg_parser(char** dest, char* src, size_t arg_max);



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
ssize_t arg_tokenize(char* token_buffer, const char* instr, size_t buffer_size)
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

 extern int arg_parser(char** dest, char* src, size_t arg_max) 
{
    UNUSED(dest);
    UNUSED(src);
    UNUSED(arg_max);

    return -1;
}

#endif