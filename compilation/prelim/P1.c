#include <stdio.h>
#include <stdbool.h>
#include "../glencrypt.h"


void printArray(double array[], int n) {
    printf("array = [");
    for (int i = 0; i < n; i++) {
        if (i >= n - 1) {
            printf("%f", array[i]);
        } else {
            printf("%f, ", array[i]);
        }
    }
    printf("]\n");
}

void printIntArray(int array[], int n) {
    printf("array = [");
    for (int i = 0; i < n; i++) {
        if (i >= n - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("]\n");
}

void initializeArray(double array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = 0.0;
    }
}

double getMin(double array[], int n) {
    double min = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

double getSum(double array[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

int countNegative(int array[], int n) {
    int negative = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] < 0) {
            negative += 1;
        }
    }
    return negative;
}

bool testInteger(int array[], int n, int x) {
    bool result = false;
    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            result = true;
            break;
        }
    }
    return result;
}

void copyArray(int A[], int B[], int n) {
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
}

void copyReverseArray(int A[], int B[], int n) {
    for (int i = 0; i < n; i++) {
        B[(n - 1) - i] = A[i];
    }
}

bool testEqual(int A[], int B[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

void exercise1P1() {
    int n = 5;
    double array[5];
    initializeArray(array, n);
    printArray(array, n);
}

void exercise2P1() {
    int n;
    input(Int, "Enter an array size: ", &n);
	if (n > 0) {
        double array[n];
        initializeArray(array, n);
        printArray(array, n);
    } else {
        printf("Invalid array size. Size should be greater than 0.\n");
    }
}

void exercise3P1() {
    int n = 5;
    double array[5] = {2.11, 2.52, 4.81, 1.99, 3.33};
    printArray(array, n);
    double min = getMin(array, n);
    printf("Lowest Value: %f\n", min);
}

void exercise4P1() {
    int n = 5;
    double array[5] = {2.11, 2.52, 4.81, 1.99, 3.33};
    printArray(array, n);
    double sum = getSum(array, n);
    printf("Sum of array: %f\n", sum);
}

void exercise5P1() {
    int n = 5;
    int array[5] = {2, -2, 0, 1, -3};
    printIntArray(array, n);
    int negative = countNegative(array, n);
    printf("Negative number count: %d\n", negative);
}

void exercise6P1() {
    int n = 5;
    int x;
    int array[5] = {2, -2, 0, 1, -3};
    printIntArray(array, n);
    input(Int, "Enter a value to test if it exists in the array: ", &x);
    bool result = testInteger(array, n, x);
    printf("Result: %s\n", result ? "true" : "false");
}

void exercise7P1() {
    int n = 5;
    int A[5] = {2, -2, 0, 1, -3};
    int B[5];
    copyArray(A, B, n);
    printf("Array A:\n");
    printIntArray(A, n);
    printf("Array B:\n");
    printIntArray(B, n);
}

void exercise8P1() {
    int n = 5;
    int A[5] = {2, -2, 0, 1, -3};
    int B[5];
    copyReverseArray(A, B, n);
    printf("Array A:\n");
    printIntArray(A, n);
    printf("Array B:\n");
    printIntArray(B, n);
}

void exercise9P1() {
    int n = 5;
    int A[5] = {5, 4, 3, 2, 0};
    int B[5] = {5, 4, 3, 2, 1};
    printf("Array A:\n");
    printIntArray(A, n);
    printf("Array B:\n");
    printIntArray(B, n);
    bool result = testEqual(A, B, n);
    printf("Result: %s\n", result ? "true" : "false");
}



