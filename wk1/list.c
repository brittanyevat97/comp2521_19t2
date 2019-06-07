#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// data structure representing a node
typedef struct Node {
    int value;
    struct node *next;
} Node;

typedef Node *List; // pointer to a Node

Node *newNode(int value) {
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    return new;
}

// Write a function to sum the values in a list
int sumOfList(List l) {

}

// Also write recursive function
int sumOfList(List l) {

}

// Print list in reverse order
void printReverse(List l) {

}

// Merge two sorted linked lists
// E.g. l1:     1->4->6->10
//      l2:     2->3->5
//      return: 1->2->3->4->5->6->10
// HINT: Try to do this recursively
List mergeLists(List l1, List l2) {

}
