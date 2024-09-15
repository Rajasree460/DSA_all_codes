/*strassen matrix mul*/
#include <stdio.h>

#define N 4

// Function to add two matrices
void add(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's matrix multiplication
void strassen(int A[N][N], int B[N][N], int C[N][N]) {
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half_size = N / 2;

    int A11[half_size][half_size], A12[half_size][half_size];
    int A21[half_size][half_size], A22[half_size][half_size];
    int B11[half_size][half_size], B12[half_size][half_size];
    int B21[half_size][half_size], B22[half_size][half_size];
    int C11[half_size][half_size], C12[half_size][half_size];
    int C21[half_size][half_size], C22[half_size][half_size];

    // Divide matrices A and B into submatrices
    for (int i = 0; i < half_size; i++) {
        for (int j = 0; j < half_size; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half_size];
            A21[i][j] = A[i + half_size][j];
            A22[i][j] = A[i + half_size][j + half_size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half_size];
            B21[i][j] = B[i + half_size][j];
            B22[i][j] = B[i + half_size][j + half_size];
        }
    }

    int M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
    int temp1[N][N], temp2[N][N];

    // Calculate seven products recursively
    add(A11, A22, temp1);
    add(B11, B22, temp2);
    strassen(temp1, temp2, M1);

    add(A21, A22, temp1);
    strassen(temp1, B11, M2);

    subtract(B12, B22, temp1);
    strassen(A11, temp1, M3);

    subtract(B21, B11, temp1);
    strassen(A22, temp1, M4);

    add(A11, A12, temp1);
    strassen(temp1, B22, M5);

    subtract(A21, A11, temp1);
    add(B11, B12, temp2);
    strassen(temp1, temp2, M6);

    subtract(A12, A22, temp1);
    add(B21, B22, temp2);
    strassen(temp1, temp2, M7);

    // Calculate submatrices of C using the results of the seven products
    add(M1, M4, temp1);
    subtract(temp1, M5, temp2);
    add(temp2, M7, C11);

    add(M3, M5, C12);

    add(M2, M4, C21);

    add(M1, M3, temp1);
    subtract(temp1, M2, temp2);
    add(temp2, M6, C22);

    // Combine the submatrices to obtain the result matrix C
    for (int i = 0; i < half_size; i++) {
        for (int j = 0; j < half_size; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half_size] = C12[i][j];
            C[i + half_size][j] = C21[i][j];
            C[i + half_size][j + half_size] = C22[i][j];
        }
    }
}

// Function to print a matrix
void print_matrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[N][N] = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    int C[N][N];

    // Perform matrix multiplication using Strassen's algorithm
    strassen(A, B, C);

    // Print the result matrix C
    printf("Resultant matrix C:\n");
    print_matrix(C);

    return 0;
}


