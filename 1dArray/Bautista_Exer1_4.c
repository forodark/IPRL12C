//Bautista, Glen Angelo D.
//Exercise 1 Number 1

#include <stdio.h>

void printArray(double array[], int n)
{
    printf("array = [");
    for(int i=0; i<n; i++) 
	{
       	if(i>=n-1)
       	{
       	    printf("%f", array[i]);
       	}
       	else
       	{
       	    printf("%f, ", array[i]);
       	}
    }
    printf("]\n");
}

double getSum(double array[], int n)
{
    double sum = 0;
    for(int i=0; i<n; i++) 
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
	int n = 5;
	double array[5] = {2.11, 2.52, 4.81, 1.99, 3.33};
    printArray(array, n);
    double sum = getSum(array, n);
    printf("Sum of array: %f", sum);
    return 0;
}