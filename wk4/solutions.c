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
    // if tree is empty, it is an AVL tree
    if (t == NULL)
        return 0;
    
    int l = isAVL(t->left);
    int r = isAVL(t->right);

    // if either left or right subtree is not an AVL tree,
    // then the whole tree is not an AVL tree
    if (l == -1 || r == -1)
        return -1;

    // check if difference between left and right subtrees
    // is more than one
    if (l - r > 1 || r - l > 1)
        return -1;

    // otherwise, tree is an AVL tree, return its height
    return (l > r ? l : r) + 1;
}
