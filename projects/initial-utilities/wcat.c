#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define BUFFER_MAX 1024

int main(int argc, char* argv[]) {

    if (argc < 2) errx(EXIT_FAILURE, "Usage: ./wcat <filename>");

    FILE* infile;

    for (int i = 1; i < argc; ++i) {

        if ((infile = fopen(argv[i], "r")) == NULL ) {
            errx(EXIT_FAILURE, "Failed to open file %s", argv[i]);
        }
        
        char buffer [1024];
    
        while(fgets(buffer, BUFFER_MAX, infile) != NULL) {
            printf("%s", buffer);
        }
        printf("\n");

        if (fclose(infile) != 0) errx(EXIT_FAILURE, "Failed to close file\n");
    }

    
}
