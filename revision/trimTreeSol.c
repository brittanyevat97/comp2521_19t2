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
    if (t == NULL)
        return NULL;
    if (t->value < min) {
        dropTree(t->left);
        BSTree ret = trimTree(t->right, min, max);
        free(t);
        return ret;
    }
    if (t->value > max) {
        dropTree(t->right);
        BSTree ret = trimTree(t->left, min, max);
        free(t);
        return ret;
    }
    t->left = trimTree(t->left, min, max);
    t->right = trimTree(t->right, min, max);
    return t;
}
