#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
Write a program that calls fork() before calling fork have the main process 
create and access a variable. Check the variable in the child process. What happens
when we modify the variable in both the parent and child process?
*/

int main(void) {

    int x = 42;
    printf("Begin parent process: (pid:%d)\nx initial value: %d\n", getpid(), x);
    int child_pid = fork();
    if (child_pid < 0) {
        fprintf(stderr, "Fork failed\n");
    } else if (child_pid == 0) {
        // we are in the child
        printf("In child: (pid:%d)\nchild x:%d\n",getpid(), x);
        // Modify x
        x = 84;
        printf("child x modifed: %d\n", x);
    } else {
        //wait(NULL);
        x = 100;
        printf("In parent: (pid:%d)\n: Parent x: %d\n", getpid(), x);
    }
}
/* 
The child recieves a copy of the variable x from parent. When x is modified by either the 
child or the parent the other is not effected.w
*/
