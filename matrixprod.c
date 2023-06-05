/*
Challenge 6: Implements dot product. 
vector-to-vector and matrix-to-vector are just all special cases 
of matrix-to-matrix multiplciation. This implements dot_product()ç
as a general dot product between arrays. It takes two arrays, 
the product buffer and the sizes of the matrices/products. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void print_array(double A[], size_t N, char *name) {
    printf("%s: ", name);

    for (size_t i = 0; i < N; i++) {
        printf("%f, ", A[i]);
    }
    printf("\n");
}

void dot_product(double x[],
                double y[],
                double product[],
                size_t sizes[3]) { // {row x, col x, col y}

    size_t m = sizes[0];
    size_t n = sizes[1]; // common size
    size_t p = sizes[2];

    // size of product is x_dims[0], y_dims[1]
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < p; j++) {
            for (size_t k = 0; k < n; k++) {
                // k moves in columns in x and rows in y
                product[j + i*p] += x[i * n + k] * y[j + k * p]; // x_ik * y_kj
            }
        }
    }
}

int main() {
    double x[] = {
        4,
        5,
        1,
        5,
        6,
    };
    double y[] = {
        1,
        34,
        5,
        6,
        7,
    };


    size_t n_vec[3] = {1, 5, 1};

    double vect_product[1] = {0};
    dot_product(x, y, vect_product, n_vec);
    printf("Matrix product of vector: \n");
    print_array(vect_product, 1, "product");


    double A[][2] = {{1, 2},
                     {4, 5},
                     {8, -1}};


    double B[][3] = {{4, 6, 1},
                     {6, 1, 3}};


    double product[9] = {0};

    size_t n_matrix[3] = {3, 2, 3};
    dot_product(A, B, product, n_matrix);
    printf("Matrix product: \n");
    print_array(product, 9, "product");



    return EXIT_SUCCESS;
}