#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <ctype.h>


/* Write a program to use some amount of memory and run forever!*/
int main(int argc, char* argv[]){

	char* buffer;
	size_t mem = 1000;
	if (argc == 2) {
	  for(size_t i = 0; i < strlen(argv[1]); ++i) {
      if(!isdigit(argv[1][i])) {
        fprintf(stderr, "please enter only digits as the second argument\n");
        exit(1);
        
      }
    }
	} else if (argc > 2){
		fprintf(stderr, "usage: ./memory-user <memory in MB>\n");
		exit(1);
	} else {
		printf("Using default memory 1GB\n");
	}

	assert((buffer = malloc(mem * 1000000)) != NULL);

	printf("Running loop iteration... (PID %d)\n", getpid());
	while(1) {
		for (size_t i = 0; i < mem * 1000000; ++i) {
			buffer[i] = (char) (i % 255);
		}
	}
	char* src = "Hello world!";
	char buffer[256];
	strncpy(buffer, src, 10);
	free(buffer);
}
