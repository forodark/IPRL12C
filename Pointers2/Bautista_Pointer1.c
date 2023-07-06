#include <stdio.h>
#include <stdlib.h>
#include "glencrypt.h"

void showMenu();
void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();
void exercise7();
void exercise8();
void exercise9();
void exercise10();
int sum(int a, int b);
void add(int *pc, int a, int b);
void getSumAve(float A[], float *sum, float *ave, int size);

int main() {
	showMenu();
	return 0;
}


void showMenu() {
	printf("Exercises on Pointers\n");
	printLine(0);
    printf("[1] Exercise 1\n");
    printf("[2] Exercise 2\n");
    printf("[3] Exercise 3\n");
    printf("[4] Exercise 4\n");
    printf("[5] Exercise 5\n");
    printf("[6] Exercise 6\n");
    printf("[7] Exercise 7\n");
    printf("[8] Exercise 8\n");
    printf("[9] Exercise 9\n");
    printf("[10] Exercise 10\n");	    
	printf("[0] Exit\n");
    printLine(0);
    while(1) {
    	int choice;
		input(INT, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	exercise1();
				printLine(0);
				break;
			case 2:
            	exercise2();
				printLine(0);
				break;
			case 3:
				exercise3();
				printLine(0);
				break;
			case 4:
				exercise4();
				printLine(0);
				break;
			case 5:
				exercise5();
				printLine(0);
				break;
			case 6:
				exercise6();
				printLine(0);
				break;
			case 7:
				exercise7();
				printLine(0);
				break;
			case 8:
				exercise8();
				printLine(0);
				break;
			case 9:
				exercise9();
				printLine(0);
				break;
			case 10:
				exercise10();
				printLine(0);
				break;
			case 0:
				printf("Exiting Program...\n");
				exit (0);	
				break;
			default:
				printf("Invalid choice.\n");
		}
	}
}

void exercise1() {
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


void exercise2() {
	double d;
	double *pd;
	
	pd = &d;
	input(DOUBLE, "Input a value: ", pd); // i replaced scanf() and printf() with my custom input() function to handle invalid input error
	//The value of d, will be whatever the user inputs using the scanf() function
	//This is because scanf() takes a parameter containing an address like scanf("%d", &input);
	//since pd contains the address of d, scanf will write the input to that address
	printf("d = %.2lf\n", d);
}

void exercise3() {
	int a = 1;
    int b = 2;
    int c_sum;
    int c_add;

    c_sum = sum(a, b);
    printf("Sum using sum(): %d\n", c_sum);

    add(&c_add, a, b);
    printf("Sum using add(): %d\n", c_add);
    //I would say that both have their use cases, but in general, add() is a bit better as it does not need to create a new local variable to store the sum.
}

int sum(int a, int b) { // takes a and b as parameters and returns c
    int c;
    c = a + b;
    return c;
}

void add(int *pc, int a, int b) { // takes a, b, and a pointer pc as parameters. modifies the address directly.
    *pc = a + b;
}

void exercise4() { // I added an aditional size parameter, so that it can work with any number of elements in A
	float A[] = {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5};
	int size = sizeof(A) / sizeof(A[0]);
	float sum, ave;
	
	getSumAve(A, &sum, &ave, size);
	printf("Sum: %.2f\tAverage: %.2f\n", sum, ave);
}

void getSumAve(float A[], float *sum, float *ave, int size) {
	*sum = 0.0;

    for (int i = 0; i < size; i++) {
        *sum += A[i];
    }
    *ave = *sum/size;
}

void exercise5() {
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

void exercise6() {
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

void exercise7() {
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

void exercise8() {
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

void exercise9() {
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

void exercise10() {
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

