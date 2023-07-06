#ifndef GLENCRYPT_H
#define GLENCRYPT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>

#define ALPHANUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMERIC "0123456789."
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define CHARLIB "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ "
#define DEFAULTKEY "}Pj? THrxT_{Dh^Q.UdrG&s-X'?zaPBJ-2]dyFD23IV9:'&tT%]:}$m@<~[,oT$"
#define KEYGEN "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[]^_`{|}~ "


typedef enum {
    UNDEF,
    INT,
    DOUBLE,
    CHAR,
    STR,
    BOOL
} DataType;


//MISC

int getCharPos(char* str, char ch) {
    char* pos = strchr(str, ch);
    if (pos == NULL) {
        return -1;
    }
	else {
        return (int)(pos - str);
    }
}



//Encryption


const char* keyEncrypt(char input[], char key[]) {
    static char output[256];
    int converted_input[256];
    int converted_key[256];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] + converted_key[x]) % strlen(lib);
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}

const char* keyDecrypt(char input[], char key[]) {
    static char output[256];
    int converted_input[256];
    int converted_key[256];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] - converted_key[x] + strlen(lib)) % strlen(lib);
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}


const char* encrypt(char input[]) {
    return keyEncrypt(input, DEFAULTKEY);
}

const char* decrypt(char input[]) {
    return keyDecrypt(input, DEFAULTKEY);
}


char* generateKey(int length) {
    static int initialized = 0;
    static char key[256];
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    for(int i = 0; i < length; i++) {
        key[i] = KEYGEN[rand() % strlen(KEYGEN)];
    }
    key[length] = '\0';
    return key;
}




//COSMETIC STUFFS
void printLine(int type) {
	switch(type) {
		case 0: //normal
			printf("---------------------------------\n");
			break;
		case 1: //fancy
			printf("->->-~-~-~-=-=-=-=-=-=-~-~-~-<-<-\n");
			break;
		case 2: //long
			printf("------------------------------------------------------------------\n");
			break;
		default:
			printf("---------------------------------\n");
			break;
	}
}


//CHECKS

int isEmpty(const char *input) {
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        if (!isspace(input[i])) {
            return 0;
        }
    }
    return 1;
}


//IMPROVED INPUT

void input(int datatype, char prompt[256], void* output) {
    if (datatype == 0){ //unspecified

    }
    else if (datatype == 1) {
        while(1) {
            printf("%s", prompt);
            char buffer[256];
            int temp;
            fgets(buffer, 256, stdin);
            if (isEmpty(buffer)) {
                printf("Invalid input. Input must not be empty.\n");
                printLine(0);
            }
            else {
                char* endptr;
                temp = strtol(buffer, &endptr, 10);
                if (*endptr != '\n' && *endptr != '\0') {
                    printf("Invalid input. Input must be an integer.\n");
                    printLine(0);
                }
                else {
                    *(int*)output = temp;
                    return;
                }
            }
        }
    }
    else if (datatype == 2) { //double
        while (1) {
            printf("%s", prompt);
            char buffer[256];
            double temp;
            fgets(buffer, 256, stdin);
            if (isEmpty(buffer)) {
                printf("Invalid input. Input must not be empty.\n");
                printLine(0);
            }
            else {
                int end_ptr;
                if (sscanf(buffer, "%lf%n", &temp, &end_ptr) != 1 || buffer[end_ptr] != '\n') {
                    printf("Invalid input. Please enter a valid double.\n");
                    printLine(0);
                }
                else {
                    *(double*)output = temp;
                    return;
                }
            }
        }
    }
    else if (datatype == 3) { //char
        while (1) {
            printf("%s", prompt);
            char buffer[256];
            fgets(buffer, 256, stdin);
            if (isEmpty(buffer)) {
                printf("Invalid input. Input must not be empty.\n");
                printLine(0);
            }
            else if (strlen(buffer) > 2) {
                printf("Invalid input. Input must be a single character.\n");
                printLine(0);
            }
            else {
                *(char*)output = buffer[0];
                return;
            }
        }
    }

    else if (datatype == 4) { // string
        while(1) {
            printf("%s", prompt);
            char buffer[256];
            fgets(buffer, 256, stdin);
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n') {
                buffer[--len] = '\0';
            }
            if (!isEmpty(buffer)) {
                strcpy((char*)output, buffer);
                return;
            } else {
                printf("Invalid input. Input must not be empty.\n");
                printLine(0);
            }
        }
    }


    else if (datatype == 5) { //bool (int but accepts y/n/1/0)
        while (1) {
            printf("%s", prompt);
            char buffer[256];
            fgets(buffer, 256, stdin);
            if (buffer[0] == 'y' || buffer[0] == 'Y' || buffer[0] == '1') {
                *(int*)output = 1;
                return;
            }
            else if (buffer[0] == 'n' || buffer[0] == 'N' || buffer[0] == '0') {
                *(int*)output = 0;
                return;
            }
            else {
                printf("Invalid input. Input must be 'y' or 'n'.\n");
                printLine(0);
            }
        }
    }
    else {
        printf("Invalid datatype.\n");
        printLine(0);
    }
}


void inputCustom(char prompt[256], void* output, char accepted[64]) {
    while(1) {
        printf("%s", prompt);
        char buffer[256];
        char invalid_char[256];
        memset(invalid_char, '\0', sizeof(invalid_char));
        fgets(buffer, 256, stdin);
        
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[--len] = '\0';
        }
        
        if (isEmpty(buffer)) {
            printf("Invalid input. Input must not be empty.\n");
            printLine(0);
        }
        else {
            int n = strlen(buffer);
            int m = strlen(accepted);
            int x = 0;

            int invalid = 0;

            for(int i=0; i < n; i++) {
                int char_is_valid = 0;
                for(int j=0; j < m; j++) {
                    if (buffer[i] == accepted[j]) {
                        char_is_valid = 1;
                        break;
                    }
                }
                if (!char_is_valid) {
                    invalid = 1;
                    if (!strchr(invalid_char, buffer[i])) {
                        invalid_char[x] = buffer[i];
                        x += 1;
                    }
                }
            }
            invalid_char[x] = '\0';
            if (invalid == 0) {
                strcpy((char*)output, buffer);
                return;
            }
            else {
                printf("Invalid input. Input cannot contain '%s'.\n", invalid_char);
                printLine(0);
            }
        }
    }
}

#define printVarName(x) return #x

void printTable(int numRecords, int numFields, ...)
{
    va_list args;
    va_start(args, numFields);

    // Print table header
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < numFields; i++)
    {
        const char* field = va_arg(args, const char*);
        printf("%-9s | ", field);
    }
    printf("\n");

    // Print table rows
    for (int i = 0; i < numRecords; i++)
    {
        for (int j = 0; j < numFields; j++)
        {
            if (j > 0) printf(" | ");  // Add separator

            const char* formatSpecifier = va_arg(args, const char*);
            if (strcmp(formatSpecifier, "%d") == 0)
            {
                int* value = va_arg(args, int*);
                printf("%-8d", *value);
            }
            else if (strcmp(formatSpecifier, "%s") == 0)
            {
                const char* value = va_arg(args, const char*);
                printf("%-19s", value);
            }
            else if (strcmp(formatSpecifier, "%.2f") == 0)
            {
                double* value = va_arg(args, double*);
                printf("%-15.2f", *value);
            }
        }
        printf("\n");
    }

    // Print table footer
    printf("------------------------------------------------------------------\n");

    va_end(args);
}


//ARRAY STUFFS
//void printArray(void *arr, int size) {
//    char *p = (char *)arr;
//    for (int i = 0; i < size; i++) {
//        printf("%d ", *(p + i));
//    }
//    printf("\n");
//}




#endif
