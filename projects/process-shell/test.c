#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argparse.h"


int main(void) {

    char buffer[256];
    
    
    arg_tokenize(buffer, "hello", 256);
    if (0 == strcmp("hello", buffer)) {
        printf("Passed test 1!\n");
    } else {
        printf("Failed test 1 output: %s", buffer);
    }

    arg_tokenize(buffer, "      world ", 256);
    if(0 == strcmp("world", buffer)) {
        printf("Passed test 2!\n");
    } else {
        printf("Failed test 2 output: %s", buffer);
    }

    char* test_3_string = "Hello world!";
    arg_tokenize(buffer, test_3_string, 256);
    arg_tokenize(buffer, test_3_string, 256);
    if(0 == strcmp("world!", buffer)) {
        printf("Passed test 3!\n");
    } else {
        printf("Failed test 3 output: %s", buffer);
    }

    char* test_4_string = "Hello world!";
    arg_tokenize(buffer, test_4_string, 256);
    arg_tokenize(buffer, test_4_string, 256);
    if(0 == arg_tokenize(buffer, test_4_string, 256)) {
        printf("Passed test 4!\n");
        //printf("Buffer contents for testing: %s\n", buffer);
    } else {
        printf("Failed test 4 output: %s", buffer);
    }

    char* test_5_string = "The Mad King!";
    arg_tokenize(buffer, test_5_string, 256);
    arg_tokenize(buffer, test_3_string, 256);
    arg_tokenize(buffer, test_5_string, 256);
    if(0 == strcmp("The", buffer)) {
        printf("Passed test 5!\n");
    } else {
        printf("Failed test 5 output: %s", buffer);
    }

    char* test_6_string = "sinking into flames really slow motion";
    arg_tokenize(buffer, test_6_string, 256);
    arg_tokenize(buffer, test_6_string, 256);
    arg_tokenize(buffer, test_6_string, 256);
    if(0 == strcmp("flames", buffer)) {
        printf("Passed test 6!\n");
    } else {
        printf("Failed test 6 output: %s", buffer);
    }
}