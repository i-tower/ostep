#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "argparse.h"


#define MAX_ARG_LEN 256






int main(void) {
    
    char* line_ptr;
    char* path;
    size_t line_len = 0;
    ssize_t nread = 0;

    
    char* str_arena_buffer = malloc(65536);
    if (str_arena_buffer == NULL) {
        fprintf(stderr, "Failed to allocate backing buffer\n");
        exit(1);
    }
    StringArena str_arena;
    init_string_arena(&str_arena, str_arena_buffer, 65536);

    ArgsList arg_list = {
        .len = 0,
        .size = 16,
        .list = malloc(sizeof(char*) * 16)
    };
    
    if (arg_list.list == NULL) {
        fprintf(stderr, "malloc failed in arg list\n");
        exit(1);
    }
    
    char arg_buffer[256];    
    
    while(1) {
        
        printf("wish> ");
        if ((nread= getline(&line_ptr, &line_len, stdin)) < 0) {
            exit(1);
        } else if (nread > MAX_ARG_LEN) {
            fprintf(stderr, "Input too long\n");
            exit(1);
        }
        //HACK: Eventually handle this with arg parsing library.
        // should return a null terminated array of char*s 
        // first entry is file name subsequent entries are arguments
        // TODO: Extract command line arguments

        //int parse_args(char **dest, char *src)
        //HACK: Eventually hand the string to the argument parser
        //Set the newline character to 0; FIXME: Does this work with eof? 
        line_ptr[nread - 1] = '\0';

        //HACK: Should I use length strings? Perhaps the parsing lib should but I think
        // the top level program should use standard c strings?

        memcpy(arg_buffer, line_ptr, nread);
        arg_list[0] = arg_buffer;
        arg_list[1] = NULL; 

        //HACK: Do path things. We should have an array/linked list of all the paths
        if((asprintf(&path,"/usr/bin/%s%c", arg_buffer, '\0')) < 0){
            fprintf(stderr, "Allocation failed in asprintf for path\n");
        }
        
       

        if (fork() == 0) {
            // We are the child
            if((execv(path, arg_list)) < 0) {
                perror(NULL);
                exit(1);
            }
            
        } else {
            // Parent process
            wait(NULL);
        }

    }

    free(line_ptr);
    free(path);
    return 0;
}