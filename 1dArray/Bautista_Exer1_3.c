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

double getMin(double array[], int n)
{
    double min = array[0];
    for(int i=1; i<n; i++) 
    {
        if(array[i] < min) 
        {
            min = array[i];
        }
    }
    return min;
}

int main()
{
	int n = 5;
	double array[5] = {2.11, 2.52, 4.81, 1.99, 3.33};
    printArray(array, n);
    double min = getMin(array, n);
    printf("Lowest Value: %f", min);
    return 0;
}