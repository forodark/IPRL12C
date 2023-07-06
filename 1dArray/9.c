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

bool testEqual(int A[], int B[], int n)
{
    bool result = 1;
    for(int i=0; i<n; i++) 
    {
        if(A[i] != B[i])
        {
            result = 0;
        }
    }
    return result;
}

int main()
{
	int n = 5;
	int A[5] = {5, 4, 3, 2, 0};
	int B[5] = {5, 4, 3, 2, 1};
    printf("Array A:\n");
    printArray(A, n);
    printf("Array B:\n");
    printArray(B, n);
    bool result = testEqual(A, B, n);
    printf("Result: %d", result);
    return 0;
}