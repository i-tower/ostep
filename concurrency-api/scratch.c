#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <assert.h>
#include <err.h>

void* work(void* c)
{
    printf("Hello from %s\n", (char*) c);
    return 0;
}

int main(void)
{
    pthread_t p1;
    pthread_t p2;
    char *a = "a";
    char *n = "b";

    
    puts("From main");

    if (pthread_create(&p1, NULL, work, a) < 0) errx(1, "pthread_create\n");
    if (pthread_create(&p2, NULL, work, n) < 0) errx(1, "pthread_create\n");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    puts("End from main");

    return 0;
    
}