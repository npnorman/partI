//hello world in c

#include <stdio.h>
#include <stdlib.h>

//define a node in the linked list
typedef struct node {
    int data; //this needs to be a heap allocated string
    struct node* next; //pointer to next element
    struct node* prev; //pointer to previous element
} Node;

//function prototypes
//insert, find, and delete the list
struct node* createNode(int data);
void insert(struct node*, struct node*);

//make some pointers
struct node* head = NULL;
struct node* tail = NULL;

int main() {

    printf("Hello World!\n"); //printing hello world

    //test linked list
    //create a node to store in the head
    head = createNode(7);
    printf("creating node\n");
    insert(head, createNode(8));

    printf("Head: %d\n", head->data);
    printf("Head->next: %d\n", head->next->data);

    insert(head, createNode(9));

    printf("Head->next: %d\n", head->next->next->data);

    return(0);
} //end main

struct node* createNode(int data) {
    //create a new node containing the data
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void insert(struct node* head_node, struct node* new_node) {

    //start at node,
    //if node next is null, base case, insert
    if (head_node->next == NULL) {
        //base case
        head_node->next = new_node;
    } else {
        //else node is not null, recurse
        insert(head_node->next, new_node);
    }
}