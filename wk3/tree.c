#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

BSTree newNode(int v) {
    BSTree new = malloc(sizeof(BSTNode));
    assert(new != NULL);
    new->value = v;
    new->left = new->right = NULL;
    return new;
}

// insert a new value into a binary search tree
BSTree insert(BSTree t, int v) {

}

// recursive version
BSTree insertR(BSTree t, int v) {

}

// count number of nodes in a BSTree
int numNodes(BSTree t) {

}

// count the number of internal nodes in a BSTree
int countInternal(BSTree t) {

}

// return the depth of the node containing a given key if it exists,
// -1 otherwise
// the depth of a root node is zero
int nodeDepth(BSTree t, int key) {

}

// compute the maximum branch length of a BSTree
// the branch length is the number of edges on the longest path from
// the root to a leaf
int BSTreeMaxBranchLen(BSTree t) {

}

// compute the width of a BSTree
int BSTWidth(BSTree t) {

}
