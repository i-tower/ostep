#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Homework question 7: Write a program which creates a child which then closes
the standard output. What happens if the child tries to printf() after closing 
the descriptor
*/

int main(void) {

    int pid = fork();

    if (pid == 0) {
        printf("Before closing\n");
        close(STDOUT_FILENO);
        // looks like doing this causes an error!
        int err = printf("This should be interesting...\n");
        if (err < 0) {
            fprintf(stderr, "Error in printf.%d\n", err);
        };
    } else {
        wait(NULL);
        printf("Testing printf from main\n");
    }

    return 0;
}