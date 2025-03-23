#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#ifndef NUMCPUS
#define NUMCPUS 1
#endif


typedef struct __counter_t {
    int             global;
    pthread_mutex_t glock;
    int             local[NUMCPUS];
    pthread_mutex_t llock[NUMCPUS];
    int             threshold;
}Counter_t;

struct args{
    int tid;
    int n;
    Counter_t* c;
};

void init(Counter_t *c, int threshold)
{
    c->threshold = threshold;
    c->global = 0;
    pthread_mutex_init(&c->glock, NULL);
    for (size_t i = 0; i < NUMCPUS; ++i) {
        c->local[i] = 0; 
        pthread_mutex_init(&c->llock[i], NULL);
    }
}

void update(Counter_t *c, int threadID, int amt)
{
    int cpu = threadID % NUMCPUS;
    pthread_mutex_lock(&c->llock[cpu]);
    c->local[cpu] += amt;
    if(c->local[cpu] >= c->threshold) {
        pthread_mutex_lock(&c->glock);
        c->global += c->local[cpu];
        pthread_mutex_unlock(&c->glock); 
        c->local[cpu] = 0;
    }
    pthread_mutex_unlock(&c->llock[cpu]);
}

void conclude(Counter_t *c)
{
    for (size_t i = 0; i < NUMCPUS; ++i) {
        pthread_mutex_lock(&c->llock[i]);
    }

    pthread_mutex_lock(&c->glock);

    for(size_t i = 0; i < NUMCPUS; ++i) {
        c->global += c->local[i];
        c->local[i] = 0;
        pthread_mutex_unlock(&c->llock[i]);
    }

    pthread_mutex_unlock(&c->glock);
}

void* many_updates(void* args)
{
    struct args *a = (struct args*) args;
 
    for (int i = 0; i < a->n; ++i) {
        update(a->c, a->tid, 1);
    }
    return NULL;
}

int get(Counter_t *c) 
{
    pthread_mutex_lock(&c->glock);
    int val = c->global;
    pthread_mutex_unlock(&c->glock);
    return val;
}
Counter_t counter;


int main (void) { 
    
    init(&counter, 256);
    struct args args[NUMCPUS];
    pthread_t threads[NUMCPUS];


    for (size_t i = 0; i < NUMCPUS; ++i) {
        args[i].c = &counter;
        args[i].n = 1e9;
        args[i].tid = i;
        pthread_create(&threads[i], NULL, many_updates, &args[i]);
    }

    int ccounter = 0;
    int total = 0;
    for(int prev_c = 0; prev_c != (ccounter = get(&counter)); prev_c = ccounter, ++total){ 
        if(total % 10000 == 0){
            printf("Counter is: %d\n", ccounter);
        }
        
    }

    for(size_t i = 0; i < NUMCPUS; ++i) {
        pthread_join(threads[i], NULL);
    }
    conclude(&counter);
    printf("Final value: %d\n", get(&counter));
    return 0; 
}
