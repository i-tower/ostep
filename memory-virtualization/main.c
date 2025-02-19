#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    int size = atoi(argv[1]);

    printf("%s\n", argv[1]);
    
    // char* buffer = malloc(size);
    // char* src = "Hello world!";

    // strncpy(buffer, src, 10);

    char* buffer = "hello world";

    for (size_t i = 0; i < 20; ++i) {
        putc(buffer[i], stdout);
    }
    putc('\n', stdout);
}