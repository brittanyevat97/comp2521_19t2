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
    // need a parent node to keep track of previous node
    BSTree parent = NULL;
    BSTree curr = t;
    while (curr != NULL) {
        parent = curr;
        if (v < curr->value)
            curr = curr->left;
        else if (v > curr->value)
            curr = curr->right;
        else // v == curr->value
            return t;
    }
    BSTree new = newNode(v);
    if (parent == NULL) return new;
    if (v < parent->value)
        parent->left = new;
    else // v > parent->value
        parent->right = new;
    return t;
}

// recursive version
BSTree insertR(BSTree t, int v) {
    if (t == NULL) return newNode(v);
    // note use of
    //  't->left = insertR(t->left, v);'
    // instead of just
    //  'insertR(t->left, v);'
    // to make sure we are actually updating our tree
    if (v < t->value)
        t->left = insertR(t->left, v);
    else if (v > t->value)
        t->right = insertR(t->right, v);
    // note that in the case that v == t->value, none of the other
    // cases are matched, and we just return t
    return t;
}

// count number of nodes in a BSTree
int numNodes(BSTree t) {
    // base case - empty tree
    if (t == NULL) return 0;
    // general case
    return 1 + numNodes(t->left) + numNodes(t->right);
}

// count the number of internal nodes in a BSTree
int countInternal(BSTree t) {
    // consider base case first
    if (t == NULL) return 0;
    // special case when we have a node with no children
    if (t->left == NULL && t->right == NULL) return 0;
    // recursive case
    // number of internal nodes is:
    //  1 (since the root node is an internal node) +
    //  number of internal nodes in left subtree +
    //  number of internal nodes in right subtree
    return 1 + countInternal(t->left) + countInternal(t->right);
}

// return the depth of the node containing a given key if it exists,
// -1 otherwise
// the depth of a root node is zero
int nodeDepth(BSTree t, int key) {
    // base case
    if (t == NULL) return -1;
    // consider root's value and treat recursive case accordingly
    if (t->value == key) return 0;
    int depth;
    if (key < t->value)
        depth = nodeDepth(t->left);
    else
        depth = nodeDepth(t->right);
    // if we didn't find the key value in the left / right subtree, then
    // it is not possible for it to be in the tree we are looking at
    if (depth == -1) return -1;
    return 1 + depth;
}

// compute the maximum branch length of a BSTree
// the branch length is the number of edges on the longest path from
// the root to a leaf
int BSTreeMaxBranchLen(BSTree t) {
    // base case
    if (t == NULL) return 0;
    // special case when we have a node with no children
    if (t->left == NULL && t->right == NULL) return 0;
    // recursive case
    int left = BSTreeMaxBranchLen(t->left);
    int right = BSTreeMaxBranchLen(t->right);
    return 1 + (left > right ? left : right);
}

// compute the width of a BSTree
int BSTWidth(BSTree t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 3;
    return 3 + BSTWidth(t->left) + BSTWidth(t->right);
}
