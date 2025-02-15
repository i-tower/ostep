#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


/* Use exec to call /bin/ls
Try to use all the variants of ls exec() execl()  execlp() execv() execvp() execvpe()
*/

int main(void) {

    printf("Begin\n");

    char* args[] = {"ls", "-la", NULL};
    char* env[] = {"/bin", NULL};
    int pid = fork();
    if (pid == 0) {
        // we are in the child
        if (execvpe("ls", args, env)) {
            fprintf(stderr, "Error in execl\n");
        }
    } else {
        wait(NULL);
        printf("Hello from main\n");
    }

    return 0;
}


// The various forms of exec have different methods for passing command line arguments
// and use different combinations of finding the path to the specified program.
// all the variants use various combinations of both.
