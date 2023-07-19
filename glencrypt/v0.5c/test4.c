#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> // Include for va_list and va_start

#define MAX_STRING_LENGTH 100

void convertString(const char* format, char* str, ...) {
    va_list args;
    va_start(args, str);
    vsnprintf(str, MAX_STRING_LENGTH, format, args);
    va_end(args);
}

int main() {
    int intValue = 42;
    float floatValue = 3.14;
    double doubleValue = 2.71828;
    char* stringValue = "Hello, world!";

    char buffer[MAX_STRING_LENGTH];

    // Using the function with different data types and formats
    convertString("%d", buffer, intValue);
    printf("int: %s\n", buffer);

    convertString("%.2f", buffer, floatValue);
    printf("float: %s\n", buffer);

    convertString("%.2lf", buffer, doubleValue);
    printf("double: %s\n", buffer);

    convertString("%s", buffer, stringValue);
    printf("char*: %s\n", buffer);

    return 0;
}
