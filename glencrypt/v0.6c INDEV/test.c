#include <stdio.h>   // For snprintf
#include <stdlib.h>  // For system
#include <unistd.h>  // For getcwd, chdir, and access
#include "glencrypt.h"


int main() {
    int i;
    double d;
    char c;
    char str[256];
    char str2[256];
    int b;

    input(int, "Enter int: ", &i);
    printf("Number: %d\n", i);

    input(double, "Enter double: ", &d);
    printf("Number: %lf\n", d);

    input(char, "Enter char: ", &c);
    printf("Number: %c\n", c);

    input(char*, "Enter string: ", str);
    printf("Number: %s\n", str);

    input(string, "Enter string: ", str2);
    printf("Number: %s\n", str2);

    input(bool, "Enter bool: ", &b);
    printf("Number: %d\n", b);

    return 0;
}