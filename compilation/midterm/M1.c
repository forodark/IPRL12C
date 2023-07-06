#include <stdio.h>
#include "../glencrypt.h"

void example1M1();
void example2M1();
void example3M1();
void example4M1();
void exampleb1M1();
void exampleb2M1();
void exampleb3M1();
void examplec1M1();
void examplec2M1();
void examplec3M1();
void exampled1M1();
void exampled2M1();
void exampled3M1();
void swapM1(int *px, int *py);


void example1M1() { //Access the contents of a through *pa
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

void example2M1() { // Same as exercise 1
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

void example3M1() { //Same with exercise 2 but reverse order
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

void example4M1() { //Alterative way to print that doesent use *pa
    int a[5];
    int i;

    for (i = 0; i < 5; i++)
        a[i] = 5 - i;

    for (i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, *(a + i)); 
    }
}

void exampleb1M1() { //shows incrementing of pointers through pa++
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

void exampleb2M1() { // another way to increment in a specific way also using negatives
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

void exampleb3M1() { // Uses a for loop for incrementing and printing
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

void examplec1M1() { // memory allocation and deallocation
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

void examplec2M1() { // dynamic memory allocation of multiple elements
	
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

void examplec3M1() { // alternative to example 2
	
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

void exampled1M1() { // Simply shows an example on how to use address and dereference operator
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

void exampled2M1() { // Shows how multiple pointers can point to the same address
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

void exampled3M1() { // Swaps the value between the memory of x and y
	int x = 5;
	int y = 10;

	swapM1(&x, &y); // pass the addresses of x and y as parameters

	printf("x = %d, y = %d\n", x, y);
}
	
void swapM1(int *px, int *py) {
	int temp; //temp var to store the value of x

	temp = *px; //saves value of x to temp
	*px = *py; //sets the value of x to y
	*py = temp; //sets the value of y to x (stored in temp)
}
