// Simple program to display use of argc, argv,
// and redirection of stdin, stdout, and stderr
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // These lines display the use of argc and argv
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // Use these lines to display use of redirecting
    // stdin and stdout
    // e.g. Create a file called 'in' with the contents
    // being any number, then run './a.out < in' to 
    // redirect stdin to this file
    // Run './a.out > out' to redirect stdout to a new
    // file 'out'
    int n;
    scanf("%d", &n);
    printf("Number entered: %d\n", n);

    // Use these lines to display use of redirecting
    // stdout and stderr
    // Run './a.out > out' to redirect stdout
    // './a.out 2> out' to redirect stderr
    // './a.out &> out' to redirect both
    fprintf(stdout, "HELLO\n");
    fprintf(stderr, "ERROR\n");

    return 0;
}
