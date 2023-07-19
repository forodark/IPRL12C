#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

char* typeFromFormat(char* format) {
    int length = strlen(format);
    int i = 0;

    while (i < length) {
        if (format[i] == '%') {
            i++; // Skip the '%'

            // Skip flags and width field
            while (i < length && (format[i] == '-' || format[i] == '+' || format[i] == ' ' || format[i] == '0' || format[i] == '#' || format[i] == '*')) {
                i++;
            }

            // Skip width field (numeric characters)
            while (i < length && format[i] >= '0' && format[i] <= '9') {
                i++;
            }

            // Check if there is a precision specifier
            if (format[i] == '.') {
                i++; // Skip the '.'

                // Skip precision field (numeric characters)
                while (i < length && format[i] >= '0' && format[i] <= '9') {
                    i++;
                }
            }

            // Check for format specifier characters (e.g., "lf", "f", "d", "s")
            if (i < length && (format[i] == 'l' || format[i] == 'f' || format[i] == 'd' || format[i] == 's')) {
                char specifier[3] = { format[i], '\0', '\0' };

                if (format[i] == 'f') {
                    return "float";
                } else if (format[i] == 'd') {
                    return "int";
                } else if (format[i] == 's') {
                    return "char*";
                }

                if (format[i] == 'l') {
                    specifier[1] = 'l';
                    i++; // Skip the second 'l'
                }

                if (strcmp(specifier, "lf") == 0 || format[i] == 'f') {
                    return "double";
                }
            }
        }

        i++;
    }

    return "unknown";
}



int main() {
    const char *format1 = "%.2f";
    const char *format2 = "%lf";
    const char *format3 = "%d";
    const char *format4 = "%s";

    const char *type1 = typeFromFormat(format1);
    const char *type2 = typeFromFormat(format2);
    const char *type3 = typeFromFormat(format3);
    const char *type4 = typeFromFormat(format4);

    printf("Format1: %s => Type: %s\n", format1, type1);
    printf("Format2: %s => Type: %s\n", format2, type2);
    printf("Format3: %s => Type: %s\n", format3, type3);
    printf("Format4: %s => Type: %s\n", format4, type4);

    return 0;
}
