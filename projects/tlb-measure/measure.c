#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "argparse.h"

#define PAGESIZE 4096


/*
Timing page files. Create a large datastructure with some number of page files. 
We are going time the time that it takes to access each page file. A loop should
iterate over each page in the data structure and modify one entry. An outer loop
should measure how long it takes to complete this operation on average.

When a tlb miss occurs there should be a noticeable jump in the average time required
to complete the inner loop.
*/


typedef struct timespec Timespec;

inline long my_difftime(const Timespec* begin, const Timespec* end) {

    if ((end->tv_sec - begin->tv_sec) != 0) {
        fprintf(stderr, "too long between times (greater than 1 second)\n");
        exit(1);
    }

    return end->tv_nsec - begin->tv_nsec;
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        // Command line argument parsing
        fprintf(stderr, "Usage: ./measure <number_of_pages> <number_of_iterations>\n");
        exit(1);
    }

    srand(time(NULL));
    
    
    unsigned long num_pages = get_int(argv[1]);
    size_t iterations = get_int(argv[2]);
    
    size_t jump = PAGESIZE / sizeof(int); 
    

    int* a_big_array;
    if ((a_big_array = malloc(PAGESIZE * num_pages)) == NULL) {
        fprintf(stderr, "malloc failed to allocate a_big_array\n");
        exit(1);
    } 


    memset(a_big_array, 0, PAGESIZE * num_pages);

    
    unsigned long total_ns = 0;
    unsigned long per_page_ns = 0;
    Timespec ts_begin;
    Timespec ts_end;
    for (size_t i = 0; i < iterations; ++i) {
        
        
        clock_gettime(CLOCK_MONOTONIC, &ts_begin);

        for(size_t j = 0; j < num_pages * jump; j += jump) {

            a_big_array[j] += 1;
        }

        clock_gettime(CLOCK_MONOTONIC, &ts_end);

        total_ns += ts_end.tv_nsec - ts_begin.tv_nsec;
        

    }
    Timespec res;
    clock_getres(CLOCK_PROCESS_CPUTIME_ID, &res);

    printf("CLOCK_PROCESS_CPUTIME_ID: Seconds: %ld NS: %ld\n", res.tv_sec, res.tv_nsec);
    printf("Total nanoseconds: %lu\n", total_ns);
    printf("Average time in ns: %ld\n", (total_ns / iterations) / num_pages);
    printf("Iterations: %ld\n", iterations);
    printf("Number of pages: %ld\n", num_pages);
}