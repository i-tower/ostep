#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include "utils.h"

#define ITERATIONS 1000

int main(void) {
    // int *x = NULL;
//    printf("%d\n", *x);
//  this should be an invalid read. maybe segfault maybe not
    // int* data = malloc(sizeof(int) * 100);
    // memset(data, 787, sizeof(int) * 100);
    //
    // free(&data[27]);
    // printf("%d\n", data[100]);

    LinkedList* list = init_list();
    
    for(int i = 0; i < ITERATIONS; ++i) {
        push_list(list, i);
    }

    // for(int i = 0; i < 10; ++i) {
        //     printf("List value: %d\n", pop_list(list));
        // }
        
        Vec* int_vec;
    if((int_vec = malloc(sizeof(Vec) + sizeof(int) * 100)) == NULL) {
        fprintf(stderr, "malloc failed initializing int_vec!\n");
        exit(1);
    }
    int_vec->size = 100;
    int_vec->top = 0;
    
    
    for (size_t i = 0; i < ITERATIONS; ++i){
        int_vec = push_vec(int_vec, (int) i);
    }

    ptrdiff_t list_length = list->tail - list->head;
    size_t list_size = list_length * sizeof(Node);
    
    printf ("Size of Node %ld\n", sizeof(Node));
    printf("Size of list: %ld\n", list_size);
    
    printf("Size of Vec: %ld\n", sizeof(Vec));
    printf("Top of Vec: %ld\n", int_vec->top);
    printf("Final size of int_vec %ld\n", int_vec->size);
    free(int_vec);
    

}
