// complex.h - interface for a complex numbers ADT

// data structure
// This is from the user's point of view
// (A pointer to the struct ComplexRep as implemented
// in the complex.c file - note that anyone using this
// ADT does not have access to the fields of the struct)

typedef struct ComplexRep *Complex;

// operations

Complex newComplex(float real, float im);

float getReal(Complex c);

float getIm(Complex c);

Complex add(Complex c1, Complex c2);
