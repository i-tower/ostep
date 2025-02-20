#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simple_vec {
    size_t size;
    size_t top;
    int data[];
} Vec;

static inline Vec* push_vec(Vec *v, int x) 
{
    if (v->top == v->size) {
        if((v = realloc(v, sizeof(Vec) + (sizeof(int) * v->size * 2))) == NULL) {
            fprintf(stderr, "Realloc failed!\n");
            exit(1);
        }
        v->size *= 2;
    }
    // add int to vec;
    v->data[v->top] = x;
    ++v->top;
    
    return v;
}

static inline int pop_vec(Vec* v)
{
    // Remove int from vec;
    --v->top;
    return v->data[v->top];
}

static inline int get_from_vec(Vec* v, size_t i)
{
    return v->data[i];
}

int main(void) {
    // int *x = NULL;
//    printf("%d\n", *x);
//  this should be an invalid read. maybe segfault maybe not
    // int* data = malloc(sizeof(int) * 100);
    // memset(data, 787, sizeof(int) * 100);
    //
    // free(&data[27]);
    // printf("%d\n", data[100]);
    
    Vec* int_vec;
    if((int_vec = malloc(sizeof(Vec) + sizeof(int) * 100)) == NULL) {
        fprintf(stderr, "malloc failed initializing int_vec!\n");
        exit(1);
    }
    int_vec->size = 100;
    int_vec->top = 0;

    for (size_t i = 0; i < 6000000; ++i){
         int_vec = push_vec(int_vec, (int) i);
    }
    
    printf("Size of Vec: %ld\n", sizeof(Vec));
    printf("Top of Vec: %ld\n", int_vec->top);
    printf("Final size of int_vec %ld\n", int_vec->size);
    free(int_vec);
    

}
