#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

#define ITERATIONS 1000
/* 
In this homework assingment we will measure the cost of a system call
we could pick a 0 byte read for example and repeatedly call the function

We will also measaure the cost of a context switch
*/


int main(void){
    struct timeval times[ITERATIONS];
    struct timeval tv = {0};

    for (size_t i = 0; i < ITERATIONS; ++i){
        gettimeofday(&tv, NULL);
        //printf("Seconds:%ld, Microseconds:%ld\n", tv.tv_sec, tv.tv_usec);
        times[i] = tv; 
    }
    struct timeval result = {0};
    struct timeval sum = {0};
    
    for (size_t i = 0; i < ITERATIONS; ++i){
        //printf("Seconds:%ld, Microseconds:%ld\n", times[i].tv_sec, times[i].tv_usec);
        if (i != 0) {
            timersub(&times[i], &times[i - 1], &result);
            timeradd(&result, &sum, &sum);
        }
    }
    
    timersub(&times[100], &times[0], &result);

    printf("After sub - Seconds: %ld, Microseconds: %ld\n", sum.tv_sec, sum.tv_usec);

    return 0;
}