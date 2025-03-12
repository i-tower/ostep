#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"

// to make vscode stfu
#define true 1
#define false 0

#define PAGE_SIZE 4096



bool arg_parse_tester(StringArena *a, char** expected, char* input, int expected_count) 
{   
    ArgsList arg_list = {
        .len = 0,
        .size = 16,
        .list = malloc(sizeof(char*) * 16)
    };
    int argc = arg_parser(&arg_list, a, input);

    
    if (argc != expected_count) {
       free(arg_list.list);    
       return false;
    }
    bool ret = true;
    printf("Outside loop expected: %s\n", expected[0]);
    for (size_t i = 0; arg_list.list[i] != NULL && expected[i] != NULL; ++i) {

        if (memcmp(expected[i], arg_list.list[i], strlen(expected[i]))) {
            free(arg_list.list);
            ret = false;
        }

        printf("Expected: %s\n", expected[i]);
        printf("Actual: %s\n", arg_list.list[i]);

    }

    free(arg_list.list);
    return ret;
}

int main(void) {

    char buffer[256];
    
    printf("------- Testing tokenization --------\n");
    arg_tokenize(buffer, "hello", 0, 256);
    if (0 == strcmp("hello", buffer)) {
        printf("Passed test 1!\n");
    } else {
        printf("Failed test 1 output: %s", buffer);
    }

    arg_tokenize(buffer, "      world ", 0, 256);
    if(0 == strcmp("world", buffer)) {
  
        printf("Passed test 2!\n");
    } else {
        printf("Failed test 2 output: %s", buffer);
    }

    char* test_3_string = "Hello world!";
    arg_tokenize(buffer, test_3_string, 0, 256);
    arg_tokenize(buffer, test_3_string, 1, 256);
    if(0 == strcmp("world!", buffer)) {
        printf("Passed test 3!\n");
    } else {
        printf("Failed test 3 output: %s", buffer);
    }

    char* test_4_string = "Hello world!";
    arg_tokenize(buffer, test_4_string, 0, 256);
    arg_tokenize(buffer, test_4_string, 1, 256);
    if(0 == arg_tokenize(buffer, test_4_string, 2, 256)) {
        printf("Passed test 4!\n");
        //printf("Buffer contents for testing: %s\n", buffer);
    } else {
        printf("Failed test 4 output: %s\n", buffer);
    }

    char* test_5_string = "The Mad King!";
    arg_tokenize(buffer, test_5_string, 0, 256);
    arg_tokenize(buffer, test_3_string, 1, 256);
    arg_tokenize(buffer, test_5_string, 2, 256);
    if(0 == strcmp("The", buffer)) {
        printf("Passed test 5!\n");
    } else {
        printf("Failed test 5 output: %s", buffer);
    }

    char* test_6_string = "sinking into flames really slow motion";
    arg_tokenize(buffer, test_6_string, 0, 256);
    arg_tokenize(buffer, test_6_string, 1, 256);
    arg_tokenize(buffer, test_6_string, 2, 256);
    if(0 == strcmp("flames", buffer)) {
        printf("Passed test 6!\n");
    } else {
        printf("Failed test 6 output: %s\n", buffer);
    }

    char* test_7_string = "f";
    arg_tokenize(buffer, test_7_string, 0, 256);
    if(0 == strcmp("f", buffer)) {
        printf("Passed test 7!\n");
    } else {
        printf("Failed test 7 output: %s\n", buffer);
    }

    printf("------- Testing argument parsing -------\n");

    // Setup for calling the parser

    StringArena str_arena;
    char* backing_buffer = malloc(PAGE_SIZE * 16);
    init_string_arena(&str_arena, backing_buffer, PAGE_SIZE * 16);
    
    char *ex1 = 0, *ex2 = 0, *ex3 = 0, *ex4 = 0, *ex5 = 0;
    ex1 = "filename";
    ex2 = "arg1";
    ex3 = "arg2";

    char* expected[6] = {ex1, ex2, ex3, ex4, ex5, NULL};
    char* input;

    input = "filename arg1 arg2";
    if (!arg_parse_tester(&str_arena, expected, input, 3)) {
        
        printf("Failed test 1 output: <UNIMPLEMENTED>\n");
    } else {
        printf("Test 1 passed!\n");
    }
    
    string_arena_reset(&str_arena);
    ex1 = "f";
    ex2 = NULL;
    ex3 = NULL;
    input = "f";
    char* test_2_expected[2] = {ex1, ex2};
    if(!arg_parse_tester(&str_arena, test_2_expected, input, 1)) {
        printf("Failed test 2\n");
    } else {
        printf("Test 2 passed\n");
    }

}