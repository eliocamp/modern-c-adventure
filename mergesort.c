#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Implements merge sort */
int main(int argc , char* argv[argc+1]) {

/*
    // Build the array.
    double A[argc-1];
    for (int i = 1; i < argc; i++){
        printf("%s ", argv[i]);
        A[i-1] = strtod(argv[i], 0);
    }
    //printf("\n");
*/
    double A[] = {45, 324, 34, 5654, 123, 234, 12, 25, 22, 1, 3, 99, 84}; // Test array
    size_t N = sizeof(A) / sizeof(A[0]);

    int print_array(double A[], size_t N, char* name) {
        printf("%s: ", name);

        for (size_t i = 0; i < N; i++) {
            printf("%g, ", A[i]);
        }
        printf("\n");
        return EXIT_SUCCESS;
    }

print_array(A, sizeof(A)/sizeof(A[0]), "A");
    // Merge
    double * merge(double A[], double B[], size_t Na, size_t Nb) {

        int a_index = 0;
        int b_index = 0;
        double *C = malloc(sizeof(double)*(Na+Nb));

        while(a_index < Na && b_index < Nb) {
            if (A[a_index] > B[b_index]) {
                C[b_index + a_index] = B[b_index];
                b_index++;
            } else {
                C[b_index + a_index] = A[a_index];
                a_index++;
            }
        }

        /*
        We've reached the end of A or B.
        C is sorted as well as the rest of A or B
        */

        while (a_index < Na) {
            C[b_index + a_index] = A[a_index];
            a_index++;
        }

        while (b_index < Nb) {
            C[b_index + a_index] = B[b_index];
            b_index++;
        }

        return C;
    }


    double * mergesort(double* A, size_t N) {
        if (N == 1) {
            return A;
        }

        size_t div = N/2;
        double A_left[div];
        double A_right[N - div];

        memcpy(A_left, &A[0], div*sizeof(A[0]));
        memcpy(A_right, &A[div], (N - div)*sizeof(A[0]));

        memcpy(A_left, mergesort(A_left, div), div*sizeof(A[0]));
        memcpy(A_right, mergesort(A_right, (N - div)), (N - div)*sizeof(A[0]));


        return merge(A_left,
                     A_right,
                     sizeof(A_left)/sizeof(A_left[0]),
                     sizeof(A_right)/sizeof(A_right[0])
        );

    }

    memcpy(A, mergesort(A, N), N*sizeof(A));

    print_array(A, sizeof(A)/sizeof(A[0]), "A");

    return EXIT_SUCCESS;
}


