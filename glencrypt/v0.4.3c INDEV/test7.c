#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // For atoi function

int isNumericChar(char ch) {
    return isdigit(ch) || ch == '.' || ch == '-' || ch == '+';
}

int extractNumber(const char *str) {
    // Skip leading whitespaces and non-digit characters
    while (*str && !isdigit(*str)) {
        str++;
    }

    // Extract the numeric part (integral part only)
    int result = 0;
    while (*str && isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result; // Return the extracted number
}

int main() {
    const char *str = "abc12.34";

    int extractedNumber = extractNumber(str);

    printf("Extracted Number: %d\n", extractedNumber);

    return 0;
}
