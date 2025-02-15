#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 255

int main(void) {

    char input[MAX_CHARS] = {0};
    size_t i = 0;
    for (; i < MAX_CHARS; ++i) {
        if (i == MAX_CHARS - 1) return 1;
        input[i] = (char) fgetc(stdin);

        if (input[i] == EOF) break;
    }  

    printf("Number of characters: %ld\nInput string: %s\n", i + 1, input);
}