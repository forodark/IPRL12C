#include <stdio.h>
#include <stdlib.h>
#include "../glencrypt.h"

void showMenu();
void exercise1M2();
void exercise2M2();
void exercise3M2();
void exercise4M2();
void exercise5M2();
void exercise6M2();
void exercise7M2();
void exercise8M2();
void exercise9M2();
void exercise10M2();
int sumM2(int a, int b);
void addM2(int *pc, int a, int b);
void getSumAveM2(float A[], float *sum, float *ave, int size);



void exercise1M2() {
    float f;
    double d;
    
    float *pf;
    double *pd;
    
	f = 3.14;
	d = 1.618;
    
	pf = &f;
    pd = &d;
    
    printf("*pf = %f\n", *pf);
    printf("*pd = %lf\n", *pd);
    
}


void exercise2M2() {
	double d;
	double *pd;
	
	pd = &d;
	input(Double, "Input a value: ", pd); // i replaced scanf() and printf() with my custom input() function to handle invalid input error
	//The value of d, will be whatever the user inputs using the scanf() function
	//This is because scanf() takes a parameter containing an address like scanf("%d", &input);
	//since pd contains the address of d, scanf will write the input to that address
	printf("d = %.2lf\n", d);
}

void exercise3M2() {
	int a = 1;
    int b = 2;
    int c_sum;
    int c_add;

    c_sum = sumM2(a, b);
    printf("Sum using sumM2(): %d\n", c_sum);

    addM2(&c_add, a, b);
    printf("Sum using addM2(): %d\n", c_add);
    //I would say that both have their use cases, but in general, addM2() is a bit better as it does not need to create a new local variable to store the sum.
}

int sumM2(int a, int b) { // takes a and b as parameters and returns c
    int c;
    c = a + b;
    return c;
}

void addM2(int *pc, int a, int b) { // takes a, b, and a pointer pc as parameters. modifies the address directly.
    *pc = a + b;
}

void exercise4M2() { // I added an aditional size parameter, so that it can work with any number of elements in A
	float A[] = {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5};
	int size = sizeof(A) / sizeof(A[0]);
	float sum, ave;
	
	getSumAveM2(A, &sum, &ave, size);
	printf("Sum: %.2f\tAverage: %.2f\n", sum, ave);
}

void getSumAveM2(float A[], float *sum, float *ave, int size) {
	*sum = 0.0;

    for (int i = 0; i < size; i++) {
        *sum += A[i];
    }
    *ave = *sum/size;
}

void exercise5M2() {
	float A[] = {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5};
	int size = sizeof(A) / sizeof(A[0]);
    float *pf = A; 

	printf("A = ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", *pf); 
        pf++; 
    }
    printf("\n");

}

void exercise6M2() {
	double A[] = {1.55,2.55,3.55,4.55,5.55,6.55,7.55,8.55,9.55,10.55};
	int size = sizeof(A) / sizeof(A[0]);
    double *pd = A; 
	
	printf("A = ");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", *pd); 
        pd++; 
    }
    printf("\n");

}

void exercise7M2() {
	float A[] = {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5};
	int size = sizeof(A) / sizeof(A[0]);
    float *pf = &A[size-1]; 

	printf("A = ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", *pf); 
        pf--; 
    }
    printf("\n");
}

void exercise8M2() {
	double A[] = {1.55,2.55,3.55,4.55,5.55,6.55,7.55,8.55,9.55,10.55};
	int size = sizeof(A) / sizeof(A[0]);
    double *pd = &A[size-1]; 

	printf("A = ");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", *pd); 
        pd--; 
    }
    printf("\n");
}

void exercise9M2() {
    float *A = (float*)malloc(10 * sizeof(float)); //malloc for size 10 array

    if (A == NULL) {
        printf("Malloc failed.\n");
        exit(0);
    }

    for (int i = 0; i < 10; i++) { //intialize the array
        A[i] = i + 1.5; 
    }
    
	printf("A = ");
    for (int i = 0; i < 10; i++) { //print
        printf("%.2f ", A[i]);
    }
    printf("\n");

    free(A);
}

void exercise10M2() {
    double *A = (double*)malloc(10 * sizeof(double)); //malloc for size 10 array

    if (A == NULL) {
        printf("Malloc failed.\n");
        exit(0);
    }

    for (int i = 0; i < 10; i++) { //intialize the array
        A[i] = i + 1.55; 
    }
    
	printf("A = ");
    for (int i = 0; i < 10; i++) { //print
        printf("%.2lf ", A[i]);
    }
    printf("\n");

    free(A);
}

