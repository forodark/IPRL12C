#include <stdio.h>
#include <stdarg.h>

void defaulting(int width, ...) {
    if (width == -1) {
        va_list args;
        va_start(args, width);
        width = va_arg(args, int);
        va_end(args);
    }
    printf("%d\n", width);
}

int main() {
    // Call with explicit width value
    defaulting(10);

    // Call with no parameters, it will default to -1
    defaulting();

    return 0;
}
