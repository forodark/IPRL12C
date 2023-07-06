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

bool testInteger(int array[], int n, int x)
{
    bool result = 0;
    for(int i=0; i<n; i++) 
    {
        if(array[i] == x)
        {
            result = 1;
        }
    }
    return result;
}

int main()
{
	int n = 5;
	int x;
	int array[5] = {2, -2, 0, 1, -3};
    printArray(array, n);
    printf("Enter a value to test if it exists in the array: ");
    scanf("%d",&x);
    bool result = testInteger(array, n, x);
    printf("Result: %d", result);
    return 0;
}