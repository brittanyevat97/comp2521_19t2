#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// data structures representing a linked list node and a BSTree node
typedef Node *Link; 
typedef struct BSTNode *BSTree;

typedef struct Node {
    int value;
    struct node *next;
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
    Link curr = head;
    Link max = head;
    Link prev = NULL;
    Link maxPrev = NULL;

    while (curr != NULL) {
        if (curr->value > max->value) {
            max = curr;
            maxPrev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    if (maxPrev != NULL) {
        maxPrev->next = max->next;
        max->next = head;
        head = max;
    }

    return head;
}

// Alternate implementation
// Two iterations through the list: first to find max, second to find
// prev of max
Link maxToFront(Link head) {
    Link max = head;
    Link curr = head;
    while (curr != NULL) {
        if (curr->value > max->value)
            max = curr;
        curr = curr->next;
    }
    Link prev = NULL;
    curr = head;
    while (curr != max) {
        prev = curr;
        curr = curr->next;
    }
    if (prev != NULL) {
        prev->next = max->next;
        max->next = head;
        head = max;
    }
    return head;
}

// Given a linked list, return the list in reverse
// Do not create any new nodes
Link reverseList(Link head) {
    Link curr = head;
    Link prev = NULL;
    Link temp;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}


// BSTREE QUESTIONS

// Given a tree, return a "mirrored" version of the tree
BSTree invertBSTree(BSTree t) {
    if (t == NULL)
        return t;
    BSTree l = invertBSTree(t->left);
    BSTree r = invertBSTree(t->right);
    t->left = r;
    t->right = l;
    return t;
}

// Print out the values of each node in the tree in infix order
// recursively
void BSTreeInfix(BSTree t) {
    if (t == NULL)
        return;
    BSTreeInfix(t->left);
    printf("%d ", t->value);
    BSTreeInfix(t->right);
}

Link appendToList(Link l, int v) {
    Link new = newNode(v);
    if (l == NULL)
        return new;
    Link curr = l;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
    return l;
}

// Given a binary search tree and an (initally empty) linked list,
// return the list with the values of the tree in infix (ascending)
// order
// Use similar structure to previous question
// This gives O(n^2) time complexity
Link listFromTree(BSTree t, Link l) {
    if (t == NULL)
        return l;
    l = listFromTree(t->left, l);
    l = appendToList(l, t->value);
    l = listFromTree(t->right, l);
    return l;
}

// The above implementation is kinda slow, can we do better?
// This gives O(n) time complexity
Link listFromTree2(BSTree t, Link l) {
    if (t == NULL)
        return l;
    l = listFromTree2(t->right, l);
    Link new = newNode(t->value);
    new->next = l;
    l = listFromTree2(t->left, new);
    return l;
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
        StackPush(s, curr->right);
    }
}

bool isBSTreeHelper(BSTree t, int currMin, int currMax) {
    if (t == NULL)
        return true;
    if (t->value <= currMin || t->value >= currMax)
        return false;
    return isBSTreeHelper(t->left, currMin, t->value)
        && isBSTreeHelper(t->right, t->value, currMax);
}

// Return true if t is a binary search tree, false otherwise
bool isBSTree(BSTree t) {
    return isBSTreeHelper(t, INT_MIN, INT_MAX);
}
