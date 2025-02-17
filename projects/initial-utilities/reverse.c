#define _GNU_SOURCE

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFF_SIZE 1024

/* A string stack. First in last out. When a new string is pushed onto the stack
the push function checks to see if we have enough room in our string stack if not we 
allocate more room

    Array of string slices? arr: ----------------------< When push reches the end we grow the stack
                        slice 1  ^     ^^ start    ^^    But then all these pointers are potentially 
                                                        invalid because realloc can change the arr ptr...
                                start end           end

*/
typedef struct String_Stack {
    size_t top;
    size_t size; 
    char* arr[];
} String_Stack;

int main(int argc, char* argv[]) {
    if (argc < 2) errx(EXIT_FAILURE, "Usage: ./wrgep <filename>");  
    
    FILE* infile = fopen(argv[2], "r");
    if (infile == NULL) errx(EXIT_FAILURE, "Failed to open file");

    size_t buffer_size = INITIAL_BUFF_SIZE;
    ssize_t line_length = 0;
    char* buffer = malloc(INITIAL_BUFF_SIZE);

    String_Stack* line_stack = malloc(sizeof(String_Stack) + (sizeof(char*) * INITIAL_BUFF_SIZE));
    line_stack->top = 0;
    line_stack->size = INITIAL_BUFF_SIZE;
    
}

