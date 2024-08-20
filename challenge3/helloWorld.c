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
void insert(struct node* head_node, struct node* new_node);
int find(struct node* head_node, int data);
struct node* findNode(struct node* head_node, int data);
void delete(struct node* head_node, int data);

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
    printf("Head->next->next: %d\n", head->next->next->data);

    //find the nodes
    printf("Find 7: %d\n", find(head, 7));
    printf("Find 8: %d\n", find(head, 8));
    printf("Find 2: %d\n", find(head, 2));

    //delete a node
    delete(head, 8);
    printf("deleting 8\n");
    printf("Head->next: %d\n", head->next->data);


    free(head->next->next);
    free(head->next);
    free(head);
    free(tail);

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
        //current node's next = new
        //new node's previous = current
        head_node->next = new_node;
        new_node->prev = head_node;
    } else {
        //else node is not null, recurse
        insert(head_node->next, new_node);
    }
}

int find(struct node* head_node, int data) {

    if (head_node == NULL) {
        //couldnt find
        return -1;
    } else if (head_node->data == data) {
        //no next, base case
        return 0;
    } else {
        //it does have a next
        find(head_node->next, data);
    }
}

struct node* findNode(struct node* head_node, int data) {

    if (head_node == NULL) {
        //couldnt find
        return createNode(0);
    } else if (head_node->data == data) {
        //no next, base case
        return head_node;
    } else {
        //it does have a next
        findNode(head_node->next, data);
    }
}

void delete(struct node* head_node, int data) {

    //find node with data to delete
    struct node* current_node = findNode(head_node, data);

    //set the next previous to current previous
    if (current_node->next != NULL) {
        current_node->next->prev = current_node->prev;
    }
    //set the previous next to current next
    if (current_node->prev != NULL) {
        current_node->prev->next = current_node->next;
    }

    current_node->next = NULL;
    current_node->prev = NULL;

    free(current_node);
}