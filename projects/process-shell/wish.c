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
#define MAX_PATH 4096


int main(void) {

    char* line_ptr = NULL;
    size_t line_len = 0;
    ssize_t nread = 0;
    
    
    char* str_arena_buffer = malloc(65536);
    if (str_arena_buffer == NULL) {
        fprintf(stderr, "Failed to allocate backing buffer\n");
        exit(1);
    }
    StringArena str_arena;
    init_string_arena(&str_arena, str_arena_buffer, 65536);
    
    
    
    StringList arg_list = {
        .len = 0,
        .size = 16,
        .list = malloc(sizeof(char*) * 16)
    };

    
    StringList* path_list = init_path();

    
    char path[MAX_PATH];
    
    while(1) {
        
        

        if (arg_list.list == NULL) {
            fprintf(stderr, "malloc failed in arg list\n");
            exit(1);
        }

        printf("wish> ");
        if ((nread= getline(&line_ptr, &line_len, stdin)) < 0) {
            exit(1);
        } else if (nread > MAX_ARG_LEN) {
            fprintf(stderr, "Input too long\n");
            exit(1);
        }
         
        size_t arg_count = arg_parser(&arg_list, &str_arena, line_ptr);
        if (arg_count == 0) {
            fprintf(stderr, "We should never have 0 arguments...\n");
            string_arena_reset(&str_arena);
            reset_stringlist(&arg_list);
            continue;
        }

        if (strlen(arg_list.list[0]) >= 4) {

            if (!memcmp("exit", arg_list.list[0], 4)) goto end;

            if (!memcmp("path", arg_list.list[0], 4)) {
                push_stringlist()
            }
        }
        
        //HACK: Do path things. We should have an array/linked list of all the paths
        int path_len = snprintf(path, MAX_PATH, "/bin/%s%c", arg_list.list[0], '\0');
        if (access(path, F_OK) == 0) {
            printf("Access OK\n");
        } else {
            printf("Access Not Ok\n");
        }
        if(path_len < 0 || path_len >= MAX_PATH){
            fprintf(stderr, "Error in path snprintf\n");
            exit(1);
        }
        

        if (fork() == 0) {
            // We are the child
            if((execv(path, arg_list.list)) < 0) {
                perror("wish");
                exit(1);
            }
            
        } else {
            // Parent process
            wait(NULL);
        }
        
        reset_stringlist(&arg_list);
        
        string_arena_reset(&str_arena);
    }

    end:

    free(arg_list.list);
    free(line_ptr);
    free(path_list);
    free(str_arena_buffer);

    return 0;
}