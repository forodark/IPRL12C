//Bautista, Glen Angelo D.
//Exercise 1 Number 1

#include <stdio.h>

void intializeArray(double array[], int n)
{
	for(int i=0; i<n; i++) 
	{
       	array[i] = 0.0;
    }
}

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
    printf("]");
}


int main()
{
	int n = 5;
	double array[n];
    intializeArray(array, n);
    printArray(array, n);
    return 0;
}