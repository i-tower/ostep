#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "argparse.h"
#include "wishpaths.h"


#define MAX_ARG_LEN 256


int main(void) {

    char* line_ptr = NULL;
    size_t line_len = 0;
    ssize_t nread = 0;
    
    
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
    
    
    StringList* path_list = init_path();
    
    
    char path_buffer[MAX_PATH];
    
    while(1) {
        
        reset_stringlist(&arg_list);
        string_arena_reset(&str_arena);
        

        if (arg_list.list == NULL) {
            fprintf(stderr, "malloc failed in arg list\n");
            exit(1);
        }

        printf("wish> ");
        if ((nread = getline(&line_ptr, &line_len, stdin)) < 0) {
            exit(1);
        } else if (nread > MAX_ARG_LEN) {
            fprintf(stderr, "Input too long\n");
            continue;
        }
         
        size_t arg_count = arg_parser(&arg_list, &str_arena, line_ptr);
        if (arg_count == 0) {
            fprintf(stderr, "We should never have 0 arguments...\n");
            string_arena_reset(&str_arena);
            reset_stringlist(&arg_list);
            continue;
        }
        
        // Handle our commands
        if (strlen(arg_list.list[0]) >= 4) {

            if (!strcmp("exit", arg_list.list[0])) goto end;

            if (!strcmp("path", arg_list.list[0])) {
                push_path(path_list, &path_arena, arg_list.list[1]);
                continue;
            }
        }
        
        // for (size_t i = 0; i < path_list->len; ++i) {
        //     printf("Path: %s\n", path_list->list[i]);
        // }
        
        if (!resolve_path(path_list, path_buffer, arg_list.list[0])) {
            printf("File %s not found\n", arg_list.list[0]);
            continue;
        }

        if (access(arg_list.list[0], F_OK)) {
            printf("No access\n");
        } else {
            printf("Yes access\n"); 
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