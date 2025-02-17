#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>

#define INITIAL_BUFF_SIZE 1024


int main(int argc, char* argv[]) {
    if (argc < 3) errx(EXIT_FAILURE, "Usage: ./wrgep <search_string> <filename>");  
    
    FILE* infile = fopen(argv[2], "r");
    if (infile == NULL) errx(EXIT_FAILURE, "Failed to open file");

    size_t buffer_size = INITIAL_BUFF_SIZE;
    ssize_t line_length = 0;
    char* buffer = malloc(sizeof(char) * INITIAL_BUFF_SIZE);
    
    while ((line_length = getline(&buffer, &buffer_size, infile)) >= 0) {
        if (buffer == NULL) {
            free(buffer);
            errx(EXIT_FAILURE, "Getline realloc failed!!!");
        }

        if (strstr(buffer, argv[1]) != NULL) {
            printf("%s", buffer);
        }
    }

    printf("\n");
}