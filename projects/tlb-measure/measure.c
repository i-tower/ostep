#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <errno.h>
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "argparse.h"

#define PAGESIZE 4096


/*
* Timing page files. Create a large datastructure with some number of page files. 
* We are going time the time that it takes to access each page file. A loop should
* iterate over each page in the data structure and modify one entry. An outer loop
* should measure how long it takes to complete this operation on average.
*
* When a tlb miss occurs there should be a noticeable jump in the average time required
* to complete the inner loop.
*/

/*
*  Results: The speed of updating the array members seems to increase with the number 
*  of pages accessed this must be because of some caching / branch predictin going on 
*  inside the CPU. I would expect the tlb cash to miss at some point and cause a slowdown
*  but it seems like the speed increases from repeated loop iterations outweigh the tlb misses??
*/

typedef struct timespec Timespec;

/* 
*  A function for dealing with subtracting nanoseconds where the total time elapsed
*  is greater than 1 second. Since all we care about is the time in nanoseconds we
*  simply add 1 000 000 000 to the nanoseconds and return that.
*/
static inline long my_difftime(Timespec * begin, Timespec* end) {
    long begin_nsec = begin->tv_nsec;
    long end_nsec = end->tv_nsec;

    // We can just multiply by 1 billion since tv_sec is usually 0.
    begin_nsec += begin->tv_sec * 1000000000;
    end_nsec += end->tv_sec * 1000000000;

    return end_nsec - begin_nsec;
}

int main(int argc, char* argv[]) {

    errno = 0;
    

    FILE* outfile = fopen("out.txt", "w");

    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./measure <number_of_pages> <number_of_iterations>\n");
        exit(1);
    }

    srand(time(NULL));
    
    
    unsigned long num_pages = get_int(argv[1]);
    size_t iterations = get_int(argv[2]);
    size_t user_offset = 0;
    if (argc != 3) user_offset = get_int(argv[3]);
    size_t jump = PAGESIZE / sizeof(int); 
    

    int* a_big_array;
    if ((a_big_array = malloc(PAGESIZE * num_pages)) == NULL) {
        fprintf(stderr, "malloc failed to allocate a_big_array\n");
        exit(1);
    } 


    memset(a_big_array, 0, PAGESIZE * num_pages);

    
    unsigned long total_ns = 0;
    //unsigned long per_page_ns = 0;
    //Timespec ts_diff_total;

    Timespec ts_begin;
    Timespec ts_end;

    //FIXME: Tracking time this way is not returning sensible results
    // perhaps try tracking time for each iteration individually?
    // should still be the same result though.. idk
    for (size_t i = 0; i < iterations; ++i) {

        size_t rand_offset = (size_t) ((rand() + user_offset) % jump);
        //printf("random offset is: %lu\n", rand_offset);
        //size_t rand_offset = 1000;

        clock_gettime(CLOCK_MONOTONIC, &ts_begin);

        
        for(size_t j = 0; j < num_pages * jump; j += jump) {

            a_big_array[j + rand_offset] += 1;
        }

        clock_gettime(CLOCK_MONOTONIC, &ts_end);

         total_ns += my_difftime(&ts_begin, &ts_end);
        
    }

    for (size_t i = 0; i < (PAGESIZE * num_pages) / sizeof(int); ++i) {
        fprintf(outfile, "%d\n", a_big_array[i]);
    }

    //printf("CLOCK_PROCESS_CPUTIME_ID: Seconds: %ld NS: %ld\n", res.tv_sec, res.tv_nsec);
    
    printf("Total nanoseconds: %lu\n", total_ns);
    printf("Average time in ns: %ld\n", (total_ns / iterations) / num_pages);
    printf("Iterations: %ld\n", iterations);
    printf("Number of pages: %ld\n", num_pages);

    free(a_big_array);
}