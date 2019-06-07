// complex.c - implementation of the complex numbers ADT

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "complex.h"

// data structure

struct ComplexRep {
    float real;
    float im;
};

// operations

// Initialise a new complex number
Complex newComplex(float real, float im) {
    Complex new = malloc(sizeof(struct ComplexRep));
    assert(new != NULL);
    new->real = real;
    new->im = im;
    return new;
}

// Return the real part of a complex number
float getReal(Complex c) {
    return c->real;
}

// Return the imaginary part of a complex number
float getIm(Complex c) {
    return c->im;
}

// Add two complex numbers
Complex add(Complex c1, Complex c2) {
    return newComplex(c1->real + c2->real, c1->im + c2->im);
}
