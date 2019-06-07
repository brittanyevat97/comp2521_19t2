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
    int sum = 0;
    Node *curr = l;
    // Iterate through list and add each value to sum variable
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

// Also write recursive function
int sumOfList(List l) {
    // Base case when l is NULL, sum is 0
    if (l == NULL)
        return 0;
    // Otherwise we know l is not NULL
    // Recursively call our function on l->next, and add this
    // result to the value of the first element
    return l->value + sumOfList(l->next);
}

// Print list in reverse order
// Note: Think about how recursion allows us to solve this
// problem more cleanly and efficiently than using an
// iterative approach
void printReverse(List l) {
    if (l == NULL) return;
    // Note that we must call our function recursively before
    // we print the value of the first element
    // (This ensures the elements are printed in reverse)
    printReverse(l->next);
    printf("%d ", l->value);
}

// Merge two sorted linked lists
// E.g. l1:     1->4->6->10
//      l2:     2->3->5
//      return: 1->2->3->4->5->6->10
List mergeLists(List l1, List l2) {
    // If either list is NULL, we can just return the other list
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    // NOTE: Since we know at this stage neither l1 nor l2 are NULL,
    // we can happily write l1->value, l1->next, etc. knowing we
    // will not get a seg fault, nice

    // Otherwise, cover the case when the first element of l1 is
    // less than the first element of l2
    if (l1->value < l2->value) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        // Otherwise, the first element of l2 is less than or equal
        // to the first element of l1 (similar to previous case)
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}
