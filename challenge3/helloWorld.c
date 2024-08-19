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
struct node createNode(int data);
void insert(int data);

//make some pointers
struct node* head = NULL;
struct node* tail = NULL;

int main() {

    printf("Hello World!\n"); //printing hello world

    //test linked list
    //create a node to store in the head
    //head->data = 7;
    //printf("%d", head->data);

    return(0);
} //end main

void insert(int data) {

    //create a new node containing the data
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
}