#include <stdio.h>
#include <stdlib.h>

// Given a sorted array a[] of n elements,
// search for a given element x
// Return index if found, -1 otherwise
int binarySearch(int a[], int n, int x) {
    int lo = 0;
    int hi = n-1;
    while (lo <= hi) {
        // Get middle index of the array
        int mid = (lo + hi)/2;
        // Compare value at middle with x
        // Then divide problem in half
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            hi = mid - 1;
        else // a[mid] < x
            lo = mid + 1;
    }
    return -1;
}

// Recursive version
int binarySearchHelper(int a[], int lo, int hi, int x) {
    // Base case
    // Notice how this is similar to the terminating condition
    // of the while loop in the iterative version
    if (lo > hi)
        return -1;
    int mid = (lo + hi)/2;
    if (a[mid] == x)
        return mid;
    if (a[mid] > x)
        return binarySearchHelper(a, lo, mid - 1, x);
    else // a[mid] < x
        return binarySearchHelper(a, mid + 1, hi, x);
}

int binarySearchR(int a[], int n, int x) {
    return binarySearchHelper(a, 0, n-1, x);
}
