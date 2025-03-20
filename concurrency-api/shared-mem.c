#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <err.h>

struct args {
    uint64_t *n;
    pthread_mutex_t* lock;
};

void *work(void *n)
{
    struct args* a = (struct args*) n;
    

    for (size_t i = 0; i < 10000000; ++i) {
        
        if(pthread_mutex_lock(a->lock) != 0) errx(1, "pthread lock\n");
        *a->n = *a->n + 1;
        if(pthread_mutex_unlock(a->lock) != 0) errx(1, "pthread unlock\n");
    }

    return 0;
}

void* work_lock_internal(void* args)
{
    uint64_t *n = (uint64_t*) args;
    pthread_mutex_t local_lock;
    if(pthread_mutex_init(&local_lock, NULL) != 0) errx(1, "pthread internal mutex init\n");

    for(size_t i = 0; i < 10000000; ++i) {
        pthread_mutex_lock(&local_lock);
        *n = *n + 1;
        pthread_mutex_unlock(&local_lock);
    }

    pthread_mutex_destroy(&local_lock);
    return 0;
}

int main (void)
{
    pthread_t p1;
    pthread_t p2;
    uint64_t counter = 0;

    pthread_mutex_t lock;
    if(pthread_mutex_init(&lock, NULL) != 0) errx(1, "mutex init\n");

    struct args args = { .n = &counter, .lock = &lock};

    puts("Global lock:");

    if(pthread_create(&p1, NULL, work, (void*) &args) != 0 ) errx(1, "pthread_create\n");
    if(pthread_create(&p2, NULL, work, (void*) &args) != 0 ) errx(1, "pthread_create\n");
    
    pthread_join(p1, NULL);
    pthread_join(p2, NULL); 

    pthread_mutex_destroy(&lock);

    printf("Counter: %ld\n", counter);

    puts("Local lock:");
    pthread_t p3;
    pthread_t p4;
    counter = 0;
    if(pthread_create(&p3, NULL, work_lock_internal, &counter) < 0) errx(1, "pthread_creat lock internal\n");
    if(pthread_create(&p4, NULL, work_lock_internal, &counter) < 0) errx(1, "pthread_creat lock internal\n");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Counter: %ld\n", counter);
    return 0;
}