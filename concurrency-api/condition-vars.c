#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <err.h>

struct job_1_args {
    pthread_mutex_t *lock;
    pthread_cond_t *cond;
    int *ready;
};

void* job1(void* args) 
{
    struct job_1_args *a = (struct job_1_args*) args;

    puts("ZUG ZUG!");
    pthread_mutex_lock(a->lock);
    while(!(*a->ready)) {
        pthread_cond_wait(a->cond, a->lock);
        puts("Thread awake");
    }
    pthread_mutex_unlock(a->lock);
    
    puts("Job's done!");

    return 0;
}

int main (void) 
{
    pthread_t p1;
    //pthread_t p2;
    int ready = 0;

    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

    struct job_1_args j1args = {
        .lock = &lock,
        .cond = &cond,
        .ready = &ready,
    };

    if(pthread_create(&p1, NULL, job1, &j1args) != 0) errx(1, "pthread_create\n");

    for (size_t i = 0; i < 5; ++i) {
        sleep(1);
        printf("%ld\n", i + 1);
    }

    pthread_mutex_lock(&lock);
    ready = 1;
    pthread_mutex_unlock(&lock);
    pthread_cond_signal(&cond);


    puts("Main is finished!");
    
    return 0;
}