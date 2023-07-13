#include <stdio.h>
#include <stdlib.h>
#include "../glencrypt.h"


void printArray2d(double A[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.1f\t", A[i][j]);
        }
        printf("\n");
    }
}

void exercise1P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = 0.0;
        }
    }
    printArray2d(A, rows, cols);
}

void exercise2P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Input value for A[%d][%d]: ", i, j);
            input(Int, "", &A[i][j]);
        }
    }
    printArray2d(A, rows, cols);
}

void exercise3P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};

    printArray2d(A, rows, cols);
}

int exercise4P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};

    int neg = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] < 0) {
                neg += 1;
            }
        }
    }
    printf("Number of negative elements is %d.\n", neg);
}

void exercise5P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};

    for (int i = 0; i < rows; i++) {
        printf("%.1f ", A[i][i]);
    }
    printf("\n");
}

void exercise6P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};

    int row_n;
    input(Int, "Choose a row number: ", &row_n);

    double sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += A[row_n][j];
    }
    printf("Sum of elements in row %d is %lf.\n", row_n, sum);
}

void exercise7P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};

    int col_n;
    input(Int, "Choose a column number: ", &col_n);

    double sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += A[i][col_n];
    }
    printf("Sum of elements in column %d is %lf.\n", col_n, sum);
}

void exercise8P2() {
    int rows = 3;
    int cols = 3;
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};
    double B[][3] = {{2,4,6},{8,10,12},{14,16,18}};
    double C[3][3];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printArray2d(A, rows, cols);
    printf("+\n");
    printArray2d(B, rows, cols);
    printf("=\n");
    printArray2d(C, rows, cols);
}


