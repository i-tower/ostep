#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h> 
#include <sys/wait.h>

#define MAX_LEN 256

/* 
 Write a program that opens a file with the open() system call and then calls fork
 Can both the parent and child access the file descriptor returned by open()? What happens when
 they are writing to the file concurrently? 

 Both the parent and child can access the file descriptor
 When either the parent or the child accesses the file the offset from the file descriptor
 is advanced. So if we are writing the most recent write will always be at the end of the 
 file unless we call lseek or some other such function to reset the offset

*/


int main(int argc, char* argv[]) {
    
    if (argc != 2) { 
        fprintf(stderr, "usage: ./hw2 <path/to/filename>\n");
        exit(1);
    }

    char buffer[MAX_LEN] = {0};
    
    int file_desc = open(argv[1],  O_RDWR | O_TRUNC);
    int len = 0;

    int child_pid = fork();
    if (child_pid == -1) {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    }

    if (child_pid == 0) {
        // We are in child
        printf("Hello from child: (pid:%d)\n", getpid());
        // len = read(file_desc, buffer, 256);
        // if (len <= 0){
        //     fprintf(stderr, "Read error!\n");
        //     exit(1);
        // }

        char* write_buffer = "New text from child!\n";
        size_t write_len = strlen(write_buffer);
        for (size_t i = 0; i < 10; ++i ){
            if (write(file_desc, write_buffer, write_len) <= 0) {
                fprintf(stderr, "Write failed in child\n");
                exit(1);
            }
        }
        //buffer[len] = 0;
        //printf("In child contents:\n%s\n", buffer);
        
    } else {
        // we are in the parent
        printf("Hello from parent: (pid: %d)\n", getpid());
        // len = read(file_desc, buffer, 256);
        // if (len <= 0) {
        //     fprintf(stderr, "Read error!\n");
        //     exit(1);
        // }
        // buffer[len] = 0;
        //printf("In parent contents:\n%s\n", buffer);
        char* write_buffer = "New text from parent!\n";
        size_t write_len = strlen(write_buffer);
        for (size_t i = 0; i < 10; ++i ){
            if (write(file_desc, write_buffer, write_len) <= 0) {
                fprintf(stderr, "Write failed in parent\n");
                exit(1);
            }
            wait(NULL);
        }
}
    
    // Tests with writing to file using write as well
    // char* write_buffer = "NEW_TEXT\n";
    // int write_len = strlen(write_buffer);
    // if(write(file_desc, write_buffer, write_len) <= 0) {
    //     write_err:
    //     fprintf(stderr,"Write error!\n");
    //     exit(1);
    // }
    
    // //lseek(file_desc, 1, SEEK_SET);
    // len = read(file_desc, buffer, 256);
    
    // if (len < 0){
    //     goto read_err;
    // } else if (len == 0) {
    //     fprintf(stderr, "EOF reached in read! No bytes read\n");
    //     exit(1);
    // }
    // buffer[len] = 0;
    
    // printf("Contents after modification:\n%s\n", buffer);
    
    // wclose(file_desc);
    
    return 0;
    
}


