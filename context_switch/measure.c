#define _GNU_SOURCE
#include <sched.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>

#define ITERATIONS 1000000
/* 
In this homework assingment we will measure the cost of a system call
we could pick a 0 byte read for example and repeatedly call the function

We will also measaure the cost of a context switch
*/
typedef struct timeval Timeval;

typedef struct {
    double average;
    int64_t total;
    int64_t max;
    int64_t min;
    int64_t num;
} time_results;

time_results analyze_time(Timeval* tv_arr, size_t num_entries)
{
 
    Timeval result = {0};
    int64_t sum = 0;

    time_results at_results = {0};

    at_results.min = 1000000;

    for (size_t i = 1; i < num_entries; ++i){
        timersub(&tv_arr[i], &tv_arr[i - 1], &result);
        sum += result.tv_usec;
        if(result.tv_usec > at_results.max){
            at_results.max = result.tv_usec;
        }
        if (result.tv_usec < at_results.min) {
            at_results.min = result.tv_usec;
        }
        at_results.num++;
    }

    // Not handling if sum of time diff is more than 1 second...
    // if (sum.tv_sec >= 1) {
    //     fprintf(stderr, "Took too long in analyze!\n");
    //     exit(1);
    // }
    at_results.total = sum;

    at_results.average = (double) sum / (double) num_entries;

    return at_results;    
}

int main(void){
    Timeval* times = malloc(sizeof(Timeval) * ITERATIONS);
    Timeval tv = {0};

    // Fill the array with current time.
    for (size_t i = 0; i < ITERATIONS; ++i){
        gettimeofday(&tv, NULL);
        //printf("Seconds:%ld, Microseconds:%ld\n", tv.tv_sec, tv.tv_usec);
        times[i] = tv;
    }
    
    time_results results = analyze_time(times, ITERATIONS);

    printf("Simply add an entry to an array:\n");
    printf("Average: %.3lf\n", results.average);
    printf("Max:     %ld\n", results.max);
    printf("Min:     %ld\n", results.min);
    printf("Entries Paresd: %ld", results.num);
    printf("\n--------------------------------------\n\n");

    // testing with a read of size 0
    int fd = open("./test.txt", O_RDONLY);
    char *buffer = "";
    if (fd < 0) {
        fprintf(stderr, "Failed to open file\n");
        free(times);
    }

    for (size_t i = 0; i < ITERATIONS; ++i) {
        gettimeofday(&tv, NULL);
        read(fd, buffer, 0);
        times[i] = tv;
    }

    results = analyze_time(times, ITERATIONS);
    printf("Read of size 0 from file\n");
    printf("Average: %.3lf\n", results.average);
    printf("Max:     %ld\n", results.max);
    printf("Min:     %ld\n", results.min);
    printf("\n--------------------------------------\n\n");


    // Context switching
    /* 
    Parent  -> Child a
            -> Child b
               
            a sends data to b which then reads the data a_pipe and sends back to a
            a stores the time reads from the b_pipe and then sends back to b on the a_pipe
    */
    // Create a pipe
    int pipefd_a[2];
    int pipefd_b[2];

    // fcntl(pipefd_a[0], F_SETPIPE_SZ, ITERATIONS);
    // fcntl(pipefd_a[1], F_SETPIPE_SZ, ITERATIONS);
    // fcntl(pipefd_b[0], F_SETPIPE_SZ, ITERATIONS);
    // fcntl(pipefd_b[1], F_SETPIPE_SZ, ITERATIONS);
    
    if (pipe(pipefd_a) < 0) {
        fprintf(stderr, "Pipe a failed!\n");
        free(times);
        exit(1);
    }

    if (pipe(pipefd_b) < 0) {
        fprintf(stderr, "Pipe b failed!");
        free(times);
        exit(1);
    }

    printf("Got pipes!\n");
    //cpu_set_t set;

    // CPU_SET(0, &set);
    // if (sched_setaffinity(getpid(), sizeof(set), &set) == -1) {
    //     fprintf(stderr, "Error setting cpu in parent\n");
    //     exit(1);
    // } 

    // first child process
    int pid_child_a = fork();
    if (pid_child_a < 0){
        fprintf(stderr, "Fork a failed!\n");
        free(times);
        exit(1);
    } else if (pid_child_a == 0) {
        // in child a
        // Set cpu
        // if (sched_setaffinity(getpid(), sizeof(set), &set) == -1) {
        //     fprintf(stderr, "Error setting cpu in child a\n");
        //     exit(1);
        // } 
        char* child_a_data = "ayyyy";
        char* child_a_buffer[2] = {0};
        
        //printf("In child\n");
        
        for (size_t i = 0; i < ITERATIONS; ++i) {
            read(pipefd_b[0], child_a_buffer, 1);
            //printf("a reads\n");
            write(pipefd_a[1], child_a_data, 1);
            //printf("a writes\n");

        }

        
        return 0;

    } else {
        // In parent
    
        // set cpu
        // if (sched_setaffinity(getpid(), sizeof(set), &set)) {
        //     fprintf(stderr, "Set cpu failed in child b\n");
        //     exit(1);
        // }

        char* child_b_data = "azzz";
        char child_b_buffer[2] = {0};
        
        //printf("In parent\n");
        
        for (size_t i = 0; i < ITERATIONS; ++i) {
            gettimeofday(&tv, NULL);
            times[i] = tv; 
            if (write(pipefd_b[1], child_b_data, 1) < 0) perror("Bad write");
            //printf("b writes\n");
            read(pipefd_a[0], child_b_buffer, 1);
            //printf("b reads\n");
            

        }


        results = analyze_time(times, ITERATIONS);

        printf("Context switch\n");
        printf("Average: %.3lf\n", results.average);
        printf("Max:     %ld\n", results.max);
        printf("Min:     %ld\n", results.min);
        printf("Entries Paresd: %ld", results.num);
        printf("\n--------------------------------------\n\n");
        
        //printf("Child b finished!\n");
    }

    free(times);
    
    return 0;
}