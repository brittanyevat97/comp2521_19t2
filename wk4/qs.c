#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

// Return the height of a given binary tree, if it is an
// AVL tree, otherwise return -1
int isAVL(BSTree t) {

}
