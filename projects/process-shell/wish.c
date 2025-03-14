#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "argparse.h"
#include "wishpaths.h"


#define MAX_ARG_LEN 256


// TODO: Batch File: Handle command line arguments to wish
// TODO: Multiple commands in parallel with &
// TODO: Input / Output redirection

int main(int argc, char** argv) {

    char* line_ptr = NULL;
    size_t line_len = 0;
    ssize_t nread = 0;
    int batch = 0;
    int batch_file_fd;

    if (argc == 2) {
        
        if ((batch_file_fd = open(argv[1], O_RDONLY)) < 0) {
            perror("fopen");
            exit(1);
        }

        if (dup2(batch_file_fd, STDIN_FILENO) < 0) {
            perror("dup2");
            exit(1);
        } else {
            // set batch flag so we exit after first loop
            batch = 1;
        }
    }
    
    char* str_arena_buffer = malloc(65536);
    char* path_arena_buffer = malloc(65536);
    if (str_arena_buffer == NULL || path_arena_buffer == NULL) {
        fprintf(stderr, "Failed to allocate backing buffer\n");
        exit(1);
    }
    StringArena str_arena;
    StringArena path_arena;
    init_string_arena(&str_arena, str_arena_buffer, 65536);
    init_string_arena(&path_arena, path_arena_buffer, 65536);
    
    
    
    StringList arg_list = {
        .len = 0,
        .size = 16,
        .list = malloc(sizeof(char*) * 16)
    };
    
    StringList command_list = {
        .len = 0,
        .size = 16,
        .list = malloc(sizeof(char*) * 16)
    };
    
    StringList* path_list = init_path();
    
    
    char path_buffer[MAX_PATH];
    
    while(1) {
        
        reset_stringlist(&arg_list);
        string_arena_reset(&str_arena);
        

        if (arg_list.list == NULL) {
            fprintf(stderr, "malloc failed in arg list\n");
            exit(1);
        }

        if (batch == 0) {
            // only prompt if we are not doing batches.
            printf("wish> ");
        }

        if ((nread = getline(&line_ptr, &line_len, stdin)) < 0) {
            exit(0);
        } else if (nread > MAX_ARG_LEN) {
            fprintf(stderr, "Input too long\n");
            continue;
        }

        size_t command_count = get_commands(&command_list, line_ptr);
        UNUSED(command_count);
        

        size_t arg_count = arg_parser(&arg_list, &str_arena, line_ptr);
        if (arg_count == 0) {
            fprintf(stderr, "We should never have 0 arguments...\n");
            string_arena_reset(&str_arena);
            reset_stringlist(&arg_list);
            continue;
        }
        
        for (size_t i = 0; i < arg_list.len; ++i) {
            if (arg_list.list[i][0] == '&'){
                
            }
        }
        // Handle our commands
        if (strlen(arg_list.list[0]) > 0) {

            if (!strcmp("exit", arg_list.list[0])) goto end;

            if (!strcmp("path", arg_list.list[0])) {
                push_path(path_list, &path_arena, arg_list.list[1]);
                continue;
            }

            if(!strcmp("cd", arg_list.list[0]) && arg_list.len == 2) {
                if(!chdir(arg_list.list[1])) {
                    perror("cd");
                    continue;
                }
            }
        }
        
        if (!resolve_path(path_list, path_buffer, arg_list.list[0])) {
            printf("File %s not found\n", arg_list.list[0]);
            continue;
        }
       
        if (fork() == 0) {
            // We are the child
            if((execv(path_buffer, arg_list.list)) < 0) {
                perror("wish");
                exit(1);
            }
            
        } else {
            // Parent process
            wait(NULL);
        }
        
        
    }

    end:

    destroy_path(path_list);
    free(arg_list.list);
    free(line_ptr);
    free(str_arena_buffer);
    free(path_arena_buffer);

    return 0;
}