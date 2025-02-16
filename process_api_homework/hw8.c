#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* 
Write a program that creates two children and connects the std ouput of one to the
standard input of the other using the pipe() system call.
*/

int main(void){

    // read from 0 write from 1
    int pipefd[2];
    if(pipe(pipefd)) {
        fprintf(stderr, "Failed to pipe\n");
        exit(1);
    };
    printf("Pipe fd 0: %d\n Pipe fd 1: %d\n", pipefd[0], pipefd[1]);
    int pid_child_a = fork();
    
    if (pid_child_a == 0) {
        // we are in child a write from here
        printf("In child a\n");
        dup2(pipefd[1], STDOUT_FILENO);
        
        printf("this is only a test\n");
    } else {
        // we are in parent
        // I needed to move the creation of the second child in here! otherwise a runs
        // and immediately creates a second child b. Which also runs the code in 
        // the above if block twice because the pid_child_a is set to 0 when the duplicate
        // child is created. By moving the creation of the fork in here we only create the second
        // child from the parent process.
        int pid_child_b = fork();
        if (pid_child_b == 0) {
            // we are in child b read from here
            printf("In child b. it's reading time...\n");
            char buffer[256];
            dup2(pipefd[0], STDIN_FILENO);
            while(fgets(buffer, 255, stdin) != NULL) {
                printf("From child b: %s\n", buffer);
            }
        }
        wait(NULL);
        printf("Very patiently done parent\n");
    }


    return 0;
}