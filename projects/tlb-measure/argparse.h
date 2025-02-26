#ifndef ARG_PARSE
#define ARG_PARSE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
* Take a null terminated string from command line arguments and return
* an int. Checks errno for interger overflow and crashes the program if
* an overflow is detected. 
*/
unsigned long get_int(const char* arg) 
{
    errno = 0; 
    long x = strtol(arg, NULL, 10);
    if (errno == EINVAL || errno == ERANGE){
        perror("strtol");
        exit(EXIT_FAILURE);
    }

    if (x <= 0) {
        fprintf(stderr, "Arguments must be positive intergers\n");
        exit(EXIT_FAILURE);
    }

    return x;
}

#endif