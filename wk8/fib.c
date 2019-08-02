#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Implement recursive version of fib (from tutorial) which
// uses a cached array of fib(n) values
int fibR(int n, int *knownFib) {

}

int fib(int n) {
    assert(n > 0);
    int *knownFib = calloc(n+1, sizeof(int));
    assert(knownFib != NULL);
    knownFib[1] = 1;
    knownFib[2] = 1;
    int f = fibR(n, knownFib);
    free(knownFib);
    return f;
}
