#include <stdio.h>
#include "glencrypt.h"

//NOTE: glencrypt.h is used for the input() and printLine() function

void showMenu(int page);
void example1();
void example2();
void example3();
void example4();
void exampleb1();
void exampleb2();
void exampleb3();
void examplec1();
void examplec2();
void examplec3();
void exampled1();
void exampled2();
void exampled3();
void swap(int *px, int *py);

int main () {
	printLine(0);
	showMenu(1);	


}

void showMenu(int page) { // menu with pages
	switch(page) {
		case 1: {
			printf("Midterm Pointer Examples [1/2]\n");
			printLine(0);
			printf("Pointers:\n");
		    printf("[1] Example 1\n");
		    printf("[2] Example 2\n");
		    printf("[3] Example 3\n");
		    printf("[4] Example 4\n");
		    printLine(0);
		    printf("Pointer Arithmetic:\n");
		    printf("[5] Example 1\n");
		    printf("[6] Example 2\n");
		    printf("[7] Example 3\n");
		    printLine(0);
		    printf("[9] Next Page\n");
			printf("[0] Exit\n");
		    printLine(0);
		    while(1) {
		    	int choice;
				input(INT, "Enter choice: ", &choice);
				printLine(0);
				switch (choice) {
					case 1:
		            	example1();
						printLine(0);
						break;
					case 2:
		            	example2();
						printLine(0);
						break;
					case 3:
						example3();
						printLine(0);
						break;
					case 4:
						example4();
						printLine(0);
						break;
					case 5:
						exampleb1();
						printLine(0);
						break;
					case 6:
						exampleb2();
						printLine(0);
						break;
					case 7:
						exampleb3();
						printLine(0);
						break;
					case 9:
						showMenu(2);
					case 0:
						printf("Exiting Program...\n");
						exit (0);	
						break;
					default:
						printf("Invalid choice.\n");
				}
			}
			break;
		}
		
		case 2: {
			printf("Midterm Pointer Examples [2/2]\n");
			printLine(0);
		    printf("Memory Allocation:\n");
		    printf("[1] Example 1\n");
		    printf("[2] Example 2\n");
		    printf("[3] Example 3\n");
			printLine(0);
		    printf("Other:\n");
		    printf("[4] Address / Dereferencing\n");
		    printf("[5] Same Address Pointers\n");
		    printf("[6] Swap Memory Contents\n");
			printLine(0);
			printf("[9] Previous Page\n");
			printf("[0] Exit\n");
		    printLine(0);
		    while(1) {
		    	int choice;
				input(INT, "Enter choice: ", &choice);
				printLine(0);
				switch (choice) {
					case 1:
						examplec1();
						printLine(0);
						break;
					case 2:
						examplec2();
						printLine(0);
						break;
					case 3:
						examplec3();
						printLine(0);
						break;
					case 4:
						exampled1();
						printLine(0);
						break;
					case 5:
						exampled2();
						printLine(0);
						break;
					case 6:
						exampled3();
						printLine(0);
						break;
					case 9:
						showMenu(1);
					case 0:
						printf("Exiting Program...");
						exit (0);	
						break;
					default:
						printf("Invalid choice.\n");
				}
		}
			break;
		}
		default:
			exit(0);
	}
	

}

void example1() { //Access the contents of a through *pa
    int a[5];
    int *pa;
    int i;

    for (i = 0; i < 5; i++) // initializes array a with integers from 1 to 5
        a[i] = 5 - i;

    for (i = 0; i < 5; i++) { //sets the content of pa to the address of a, then prints
        pa = &a[i]; 
        printf("a[%d] = %d\n", i, *pa);
    }
}


void example2() { // Same as exercise 1
    int a[5];
    int *pa;
    int i;

    for (i = 0; i < 5; i++)
        a[i] = 5 - i;

    pa = &a[0];

    for (i = 0; i < 5; i++) { // instead of setting the value of pa to an address first, it is accessed directly through the printf function with *(pa + i)
        printf("a[%d] = %d\n", i, *(pa + i));
    }
}

void example3() { //Same with exercise 2 but reverse order
    int a[5];
    int *pa;
    int i;

    for (i = 0; i < 5; i++)
        a[i] = 5 - i;

    pa = &a[4];  

    for (i = 0; i < 5; i++) { //*(pa - i) instead of *(pa + i)
        printf("a[%d] = %d\n", i, *(pa - i)); 
    }
}

void example4() { //Alterative way to print that doesent use *pa
    int a[5];
    int i;

    for (i = 0; i < 5; i++)
        a[i] = 5 - i;

    for (i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, *(a + i)); 
    }
}

void exampleb1() { //shows incrementing of pointers through pa++
	int a[5];
	int *pa;
	int i;
	
	for (i = 0; i < 5; i++) {
		a[i] = 5 - i;
	}
	
	pa = &a[0];
	
	printf("a[0] = %d\n", *pa);
	pa++;
	printf("a[1] = %d\n", *pa);
	pa++;
	printf("a[2] = %d\n", *pa);
	pa++;
	printf("a[3] = %d\n", *pa);
	pa++;
	printf("a[4] = %d\n", *pa);
}

void exampleb2() { // another way to increment in a specific way also using negatives
	int a[5];
	int *pa;
	int i;
	
	for (i = 0; i < 5; i++) {
		a[i] = 5 - i;
	}
	
	pa = &a[0];
	
	printf("*pa = %d\n", *pa); // starts by adding 3
	pa = pa + 3;
	printf("*pa = %d\n", *pa); // then deducting 2
	pa = pa - 2;
	printf("*pa = %d\n", *pa); // then deducting 1
	pa--;
	printf("*pa = %d\n", *pa);
}

void exampleb3() { // Uses a for loop for incrementing and printing
	int a[5];
	int *pa;
	int i;
	
	for (i = 0; i < 5; i++) {
		a[i] = 5 - i;
	}

	pa = &(a[0]);
	
	for (i = 0; i < 5; i++) {
	  printf("a[%d] = %d\n", i, *pa);
	  pa++;
	}	
}

void examplec1() { // memory allocation and deallocation
	char *pch;
	int *pi;
	float *pf;
	double *pd;
	
	pch = (char *)malloc(sizeof(char)); // allocate memory dynamically
	pi = (int *)malloc(sizeof(int));
	pf = (float *)malloc(sizeof(float));
	pd = (double *)malloc(sizeof(double));
	
	*pch = 'A';	// assign data to dynamically allocated memory
	*pi = 10;
	*pf = 3.1416;
	*pd = 88.3;
	
	printf("*pch = %c\n", *pch); // prints the assigned data
	printf("*pi = %d\n", *pi);
	printf("*pf = %f\n", *pf);
	printf("*pd = %lf\n", *pd);
	
	free(pch); // free memory
	free(pi);
	free(pf);
	free(pd);
}

void examplec2() { // dynamic memory allocation of multiple elements
	
	int *pa;
	int i;
	
	pa = (int *)malloc(sizeof(int) * 5);
	if (pa == NULL) { // exit block
	  printf("ERROR: no more memory.\n");
	  exit(1);
	}
	
	for (i = 0; i < 5; i++) { // initialize the memory block
	  *(pa + i) = 5 - i;
	}
	
	for (i = 0; i < 5; i++) { // print the contents of memory block
	  printf("Element %d = %d\n", i, *(pa + i));
	}
	
	free(pa); // free memory
}

void examplec3() { // alternative to example 2
	
	int *pa;
	int i;
	
	pa = (int *)malloc(sizeof(int) * 5);
	if (pa == NULL) { // exit block
	  printf("ERROR: no more memory.\n");
	  exit(1);
	}
	
	for (i = 0; i < 5; i++) { 	// initialize the memory block
	  pa[i] = 5 - i;
	}

	for (i = 0; i < 5; i++) { 	// print the contents of memory block
	  printf("Element %d = %d\n", i, pa[i]);
	}

	free(pa); // free memory
}

void exampled1() { // Simply shows an example on how to use address and dereference operator
	char ch;
	int i;
	float f;
	double d;
	
	char *pch;
	int *pi;
	float *pf;
	double *pd;
	
	ch = 'A';
	i = 10;
	f = 3.1416;
	d = 105.1;
	
	// sample use of the address-of operator
	pch = &ch;
	pi = &i;
	pf = &f;
	pd = &d;
	
	// sample use of the dereference operator
	printf("ch = %c\n", *pch);
	printf("i = %d\n", *pi);
	printf("f = %f\n", *pf);
	printf("d = %lf\n", *pd);
}

void exampled2() { // Shows how multiple pointers can point to the same address
	int i, j;
	int *p1, *p2, *p3;
	
	p1 = &i;
	p2 = p1;
	p3 = p1; // p1, p2, p3 all points to i
	
	*p1 = 10; // note that i will be also be 10
	
	// access the value 10 directly via i
	printf("i = %d\n", i);
	
	// access the same value indirectly via
	// pointers p1, p2 and p3
	printf("*p1 = %d\n", *p1);
	printf("*p2 = %d\n", *p2);
	printf("*p3 = %d\n", *p3);

}

void exampled3() { // Swaps the value between the memory of x and y
	int x = 5;
	int y = 10;

	swap(&x, &y); // pass the addresses of x and y as parameters

	printf("x = %d, y = %d\n", x, y);
}
	
void swap(int *px, int *py) {
	int temp; //temp var to store the value of x

	temp = *px; //saves value of x to temp
	*px = *py; //sets the value of x to y
	*py = temp; //sets the value of y to x (stored in temp)
}