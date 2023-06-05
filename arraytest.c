#include <stdlib.h>
#include <stdio.h>

 void print_size(double A[][]) {
        size_t n = sizeof(A[0]);

        printf("%ld", n);
    }

int main() {

    double A[1][4]; 
    
    print_size(A);

    return EXIT_SUCCESS;
}
