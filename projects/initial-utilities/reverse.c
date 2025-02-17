#define _GNU_SOURCE

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverse.h"

#define INITIAL_BUFF_SIZE 1024

/* A string stack. First in last out. When a new string is pushed onto the stack
the push function checks to see if we have enough room in our string stack if not we 
allocate more room

    Array of string slices? arr: ----------------------< When push reches the end we grow the stack
                        slice 1  ^     ^^ start    ^^    But then all these pointers are potentially 
                                                        invalid because realloc can change the arr ptr...
                                start end           end

*/


int main(int argc, char* argv[]) {
    if (argc < 2) errx(EXIT_FAILURE, "Usage: ./reverse <filename>");  
    
    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL) errx(EXIT_FAILURE, "Failed to open file");

    ssize_t filesize = get_filesize(argv[1]);

    // Init arena
    char* arena_buffer = malloc(filesize * 2);
    if (arena_buffer == NULL) errx(EXIT_FAILURE, "Failed to allocate backing buffer");
    Arena arena;
    arena_init(&arena, arena_buffer, filesize * 2);

    //Init stack
    String_Stack stack;
    stack_init(&stack, filesize);

    char* read_buffer = NULL;
    size_t read_buffer_size = 0;
    ssize_t read_len = 0;

    while((read_len = getline(&read_buffer, &read_buffer_size, infile)) >= 0) {
        char* tmp;
        // need +1 to include the null terminator
        if((tmp = arena_alloc(&arena, read_len + 1)) == NULL) errx(EXIT_FAILURE, "arena_alloc failed");

        // here too
        memcpy(tmp, read_buffer, read_len + 1);

        push_stack(&stack, tmp);

    }
    fclose(infile);

    for(size_t i = stack.top; i > 0; --i){
        if (argc > 2) {
            // TOOD: print to outfile
        } else {
            printf("%s", pop_stack(&stack));
        }
    }

    free(read_buffer);
    free(arena_buffer);
    stack_deinit(&stack);

    
}

