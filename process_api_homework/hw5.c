#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* 
Write a program that creates a child and calls wait. Try calling wait from the child
*/

int main(void) {

    int pid = fork();

    switch (pid) {
        case 0:
            //Child
            printf("Hello from child\n");
            // if (wait(NULL) == -1) {
            //     // This seems to always produce an error which makes sense
            //     // since the child has no children of its own
            //     fprintf(stderr, "Error in child wait\n");
            //     exit(1);
            // }
            break;
        case -1:
            fprintf(stderr, "Fork failed!\n");
            exit(1);
            break;
        default:
            // in parent
            // for part 2 of this excersise we will change the call to wait to waitpid()
            // Wait pid could be useful if we need to wait for a specific child in the case
            // we have more than one child. Or if we need to specify some options such as WNOHANG
            // where we might want to take some action IF a child has exited but otherwise continue
            // with the main program.
            if (waitpid(pid, NULL, 0) == -1) {
                fprintf(stderr, "Error in parent wait\n");
            } 
            printf("Hello from parent!\n");
    }

    return 0;
}