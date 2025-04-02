/* 
    A simple binary tree for some concurrency practicce.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <err.h>
#include <stdbool.h>

typedef struct _node Node;

typedef struct _node {
    int64_t data;
    size_t depth;
    Node *nodeL;
    Node *nodeR;
}Node;

typedef struct _bintree {
    size_t n_nodes;
    Node *head;
}BinTree;

BinTree* bintree_init(BinTree* tree) {
    tree->head = NULL;
    tree->n_nodes = 0;

    return tree;
}

Node* bintree_insert_node(Node* head, int64_t n, size_t depth) 
{
    if (head == NULL) {
        head = malloc(sizeof(Node));
        if (head == NULL) errx(1, "Node malloc: %s\n", strerror(errno));

        head->data = n;
        head->depth = depth;
        head->nodeL = NULL;
        head->nodeR = NULL;
        return head;
    } else if (head->data >= n) {
        head->nodeR =  bintree_insert_node(head->nodeR, n, ++depth);
        return head;
    } else {
        head->nodeL = bintree_insert_node(head->nodeL, n, ++depth);
        return head;
    }
}

void bintree_insert(BinTree* tree, int64_t n) 
{
    Node* headptr = bintree_insert_node(tree->head, n, 0);
    if (tree->n_nodes == 0) tree->head = headptr;
    tree->n_nodes++;
}


const int64_t* bintree_search_node(Node* head, int64_t n) 
{
    if(head == NULL) {
        return NULL;
    } else if (head->data == n) {
        return &head->data;
    } else if (head->data > n) {
        return bintree_search_node(head->nodeR, n);
    } else {
        return bintree_search_node(head->nodeL, n);
    }
}

struct node_stack {
    size_t top;
    size_t size;
    Node** nodes;
};

void push(struct node_stack* ns, Node* n) {
    ns->nodes[ns->top++] = n;
}

Node* pop(struct node_stack* ns) {
    return ns->nodes[--ns->top];
}

//   0 1 2 3 4
struct node_queue {
    size_t size;
    size_t front;
    Node** nodes;
};

void enque(struct node_queue* nq, Node* n){
    nq->nodes[nq->size++] =  n;
}

Node* dequeue(struct node_queue* nq) {
    if (nq->front < nq->size) {
        return nq->nodes[nq->front++];
    }
    return NULL;
}
/*
Iterative breadth first search. 
*/
const int64_t* bintree_search_bfs(BinTree* bt, int64_t n, int print)
{
    struct node_queue nq;
    Node* nodearr[bt->n_nodes];

    nq.size = 0;
    nq.front = 0;
    nq.nodes = nodearr;
    
    Node* current_node = NULL;
    
    enque(&nq, bt->head);

    while((current_node = dequeue(&nq)) != NULL) {
        if (print) printf("Current node is %ld\n", current_node->data);
        
        if (current_node->data == n) {
            return &current_node->data;
        }

        if (current_node->nodeL != NULL) {
            enque(&nq, current_node->nodeL);
        }
        if (current_node->nodeR != NULL) {
            enque(&nq, current_node->nodeR);
        }
    }

    return NULL;
}
bool contains(Node** nodes, Node* n, size_t size) 
{
    for (size_t i = 0; i < size; ++i) {
        if(nodes[i] == n && nodes[i] != NULL) return 1;
    }

    return 0;
} 

void print_tree(BinTree* tree) 
{
    Node* nodearr[tree->n_nodes];
    struct node_stack ns = {
        .top = 0,
        .size = tree->n_nodes,
        .nodes = nodearr,
    };

    Node* nodelist[tree->n_nodes];
    struct node_stack node_list = {
        .top = 0,
        .size = tree->n_nodes,
        .nodes = nodelist,
    };

   
    Node* current_node;
    push(&ns, tree->head);
    // flatten the tree
    while (ns.top > 0) {
        current_node = pop(&ns);
        if (!contains(node_list.nodes, current_node, node_list.size)) {
            push(&node_list, current_node);
        }
        if (current_node->nodeL != NULL) {
            push(&ns, current_node->nodeL);
        }
        if (current_node->nodeR != NULL) {
            push(&ns, current_node->nodeR);
        }
    }

    size_t max_depth = 0;
    for (size_t i = 0; i < node_list.size; ++i) {
        if (node_list.nodes[i]->depth > max_depth) {
            max_depth = node_list.nodes[i]->depth;
        }
    }

    for(size_t i = 0; i < max_depth; ++i) {
        printf("Nodes at depth %ld: ", i);
        for (size_t j = 0; j < node_list.size; ++j) {
            if (node_list.nodes[j]->depth == i) {
                printf("%ld ", node_list.nodes[j]->data);
            }
        }
        printf("\n");
    }
}

const int64_t* bintree_search(BinTree* tree, int64_t n)
{
    return bintree_search_node(tree->head, n);
}

/*      
        o
        o o
    oo      oo
*/
Node* bintree_destroy_node(Node* head)
{
    if (head == NULL) return NULL;
    if(head->nodeL == NULL && head->nodeR == NULL) {
        free(head);
        return NULL;
    } 
    bintree_destroy_node(head->nodeL);
    bintree_destroy_node(head->nodeR);   
    free(head);
    return NULL;
}

void bintree_destroy(BinTree* tree)
{
    bintree_destroy_node(tree->head);
    tree->n_nodes = 0;
}

// void print_tree(Node* head)
// {
//     if(head == NULL) return;
//     printf("Node %ld\n", head->data);
//     print_tree(head->nodeL);
//     print_tree(head->nodeR);
// }


int main (void) 
{
    int64_t arr[] = {5,1,3,4,2,6,9,0,7,8};

    BinTree t;

    bintree_init(&t);

    for (size_t i = 0; i < 10; ++i) {

        bintree_insert(&t, arr[i]);
    }

    print_tree(&t);

    for (size_t i = 0; i < 11; ++i) {
        if (bintree_search(&t, i)) {
            printf("%ld is in tree\n", i);
        } else {
            puts("False");
        }

    }

    for (size_t i = 0; i < 11; ++i) {
        if(bintree_search_bfs(&t, i, 0)) {
            printf("%ld is in tree\n", i);
        } else {

            bintree_search_bfs(&t, i, 1);
            //puts("False");
        }

    }

    //print_tree(t.head);
    bintree_destroy(&t);

}