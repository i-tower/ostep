#include <sys/time.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
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
/* 
    A simple linked list
*/


typedef struct Node {
    int i;
    struct Node* next;
} Node;

typedef struct linked_list {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* init_list(void) {
    LinkedList* new_list = (LinkedList *) malloc(sizeof(LinkedList));
    if (new_list == NULL) {
        fprintf(stderr, "Malloc failed in init_list\n");
        exit(1);
    }

    // FIXME: adding the first node should probably be acomplished by the first call
    // to push_list. But then we have to check every time we push??? 
    new_list->head = (Node*) malloc(sizeof(Node));
    if (new_list->head == NULL) {
        fprintf(stderr, "Malloc failed in init_list\n");
        exit(1);
    }
    new_list->tail = new_list->head;

    return new_list;
}

void push_list(LinkedList* list, int n) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if(new_node == NULL) {
        fprintf(stderr, "malloc failed in push_list\n");
        exit(1);
    }
    new_node->next = NULL;
    new_node->i = n;
    
    list->tail->next = new_node;
    list->tail = new_node;
    
}

int pop_list(LinkedList* list) {

    int n = list->tail->i;
    
    Node* next_node = list->head;
    
    while(next_node->next->next != NULL) {
        next_node = next_node->next;
    };

    if (next_node == list->head) {
        printf("Unable to pop more from list: Head reached \n");
        return list->head->i;
    }
    // * -> * -> * -> * -> NULL
    free(list->tail);
    next_node->next = NULL;
    list->tail = next_node;

    return n;
}

int get_nth_value(LinkedList* list, int n) {
    Node* node = list->head; 

    for(int i = 0; i < n; ++i) {
        node = node->next;
    }

    return node->i;
}

/* 

    A simple int vector. Allways add aditional elements with push.
*/
typedef struct simple_vec {
    size_t size;
    size_t top;
    int data[];
} Vec;

static inline Vec* push_vec(Vec *v, int x) 
{
    if (v->top == v->size) {
        if((v = (Vec*) realloc(v, sizeof(Vec) + (sizeof(int) * v->size * 2))) == NULL) {
            fprintf(stderr, "Realloc failed!\n");
            exit(1);
        }
        v->size *= 2;
        // add int to vec;
    }
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