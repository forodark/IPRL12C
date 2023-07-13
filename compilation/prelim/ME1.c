// Bautista, Glen Angelo
// Machine Exercise 1 - March 23. 2023
#include <stdio.h>

int sum(int a, int b);
int product(int a, int b);
void printMessage();

void ME1() {
    printf("Hello world\n");
    int x = 100, y = 250;
    printf("The sum of %d and %d is %d.\n",x,y,sum(x,y));
    printf("%d\n", sum(35,45));
    printf("The sum is %d.\n",sum(x+1,y));
    printf("The product is %d.\n",product(10,2));
    for(int i=0; i<5;i++) {
        printMessage();
    }
}

int sum(int a, int b) {

    int total = 0;
    total = a+b;
    return total;
}
 
int product(int a, int b) {
    return a*b;
}

void printMessage() {
    printf("I Love C Programming!!!\n");
}
