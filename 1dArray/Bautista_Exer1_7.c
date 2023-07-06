//Bautista, Glen Angelo D.
//Exercise 1 Number 1

#include <stdio.h>
#include <stdbool.h>

void printArray(int array[], int n)
{
    printf("array = [");
    for(int i=0; i<n; i++) 
	{
       	if(i>=n-1)
       	{
       	    printf("%d", array[i]);
       	}
       	else
       	{
       	    printf("%d, ", array[i]);
       	}
    }
    printf("]\n");
}

void copyArray(int A[], int B[], int n)
{
    for(int i=0; i<n; i++) 
    {
        B[i] = A[i];
    }
}

int main()
{
	int n = 5;
	int A[5] = {2, -2, 0, 1, -3};
	int B[5];
    copyArray(A, B, n);
    printf("Array A:\n");
    printArray(A, n);
    printf("Array B:\n");
    printArray(B, n);
    return 0;
}