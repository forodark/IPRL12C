//Bautista, Glen Angelo D.
//Exercise 1 Number 1

#include <stdio.h>

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

int countNegative(int array[], int n)
{
    int negative = 0;
    for(int i=0; i<n; i++) 
    {
        if(array[i] < 0)
        {
            negative += 1;
        }
    }
    return negative;
}

int main()
{
	int n = 5;
	int array[5] = {2, -2, 0, 1, -3};
    printArray(array, n);
    int negative = countNegative(array, n);
    printf("Negative number count: %d", negative);
    return 0;
}