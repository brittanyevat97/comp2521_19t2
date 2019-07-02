#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// data structures representing a linked list node and a BSTree node
typedef Node *Link; 
typedef struct BSTNode *BSTree;

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

// LINKED LIST QUESTIONS

// Given a linked list (not necessarily sorted), move the node with the
// maximum value to the front of the list, and return the modified list
// Do not create any new nodes
Link maxToFront(Link head) {

}

// Given a linked list, return the list in reverse
// Do not create any new nodes
Link reverseList(Link head) {

}


// BSTREE QUESTIONS

// Given a tree, return a "mirrored" version of the tree
BSTree invertBSTree(BSTree t) {

}

// Print out the values of each node in the tree in infix order
// recursively
void BSTreeInfix(BSTree t) {

}

// Given a binary search tree and an (initally empty) linked list,
// return the list with the values of the tree in infix (ascending)
// order
// Use similar structure to previous question
Link listFromTree(BSTree t, Link l) {

}

// The above implementation is kinda slow, can we do better?
Link listFromTree2(BSTree t, Link l) {

}

// Note that we can also traverse a tree using a stack
// Example on board
void BSTreeInfixStack(BSTree t) {
    if (t == NULL)
        return;
    Stack s = newStack();
    BSTree curr = t;
    while (curr != NULL || !StackIsEmpty(s)) {
        while (curr != NULL) {
            StackPush(s, curr);
            curr = curr->left;
        }
        curr = StackPop(s);
        printf("%d ", curr->value);
        curr = curr->right;
    }
}

// Return true if t is a binary search tree, false otherwise
bool isBSTree(BSTree t) {

}
