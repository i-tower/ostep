#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("Hello (pid:%d)\n", getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child (pid:%d)\n", getpid());
    } else {
        int rc_wait = wait(NULL);
        printf("parent again: (pid:%d), Child: pid(%d)\n", getpid(), rc_wait);
    }
    return 0;
}

