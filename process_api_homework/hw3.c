#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/* 
write a program using fork which prints hello from the child and
goobye from the parent. Try to ensure that the child always prints 
first. Is it possible to do this without using wait()?

TEST_PHRASE
*/

volatile int child_finished = 0;

void handler(int signum) {
    if (signum == SIGCHLD) child_finished = 1;
}


int main(void) {

    printf("Begin program...\n");

    signal(SIGCHLD, handler);
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }

    
    if (rc == 0) {
        printf("Hello from child. (pid: %d)\n", getpid());

    } else {
        while(!child_finished) {};
        printf("Goodbye from parent. (pid: %d)\n", getpid());
    }

    return 0;
}

