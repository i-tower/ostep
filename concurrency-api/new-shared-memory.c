#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>


struct args {
    int n;
    int lock;
};

// Both threads can acquire the lock at the same time...
int lock_acquire( _Atomic int* lock) {
    int n;
    while(*lock);
    *lock = 1;
    return 1;
}

int lock_release(int* lock) {
    *lock = 0;
    return 0;
}

void* worker(void* value) {
    int* n = (int*) value;
    for (size_t i = 0; i < 1000000; ++i) {
        *n = *n + 1;
    }

    return 0;
}

void* worker_with_lock(void* a){
    struct args* args = (struct args*) a;
    for (size_t i = 0; i < 1000000; ++i) {
        lock_acquire(&args->lock);
        args->n = args->n + 1;
        lock_release(&args->lock);
    }
    return 0;
}
int main (void) {

    int value = 0;
    pthread_t p1;
    pthread_t p2;
    pthread_t p3;
    pthread_t p4;

    pthread_create(&p1, NULL, &worker, &value);
    pthread_create(&p2, NULL, &worker, &value);


    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("No lock end value is %d\n", value);

    struct args args = {
        .n = 0,
        .lock = 0,
    };

    pthread_create(&p3, NULL, &worker_with_lock, &args);
    pthread_create(&p4, NULL, &worker_with_lock, &args);

    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    printf("Lock end value is %d\n", args.n);


    return 0;
}
