#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

// Given a BST and a min and max value, trim the tree so that
// all its elements lie in the range [min, max]
BSTree trimTree(BSTree t, int min, int max) {

}
