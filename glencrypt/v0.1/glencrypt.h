#ifndef GLENCRYPT_H
#define GLENCRYPT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHANUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMERIC "0123456789."
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef enum {
    UNDEF,
    INT,
    DOUBLE,
    CHAR,
    STR,
    BOOL
} DataType;

//Encryption

const char* encrypt(char input[]) { //ENCRYPTION
    static char output[100]; 
    int n = strlen(input);
    
    for(int i = 0; i < n; i++) {
        output[i] = (char)((input[i]*2)-23-i); 
    }
    output[n] = '\0'; 
    
    return output;
}

const char* decrypt(char input[]) { //DECRYPTION
    static char output[100]; 
    int n = strlen(input);
    
    for(int i = 0; i < n; i++) {
        output[i] = (char)((input[i]+23+i)/2);
    }
    output[n] = '\0';
    
    return output;
}

//COSMETIC STUFFS
void printLine() {
    printf("---------------------------------\n");
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
                printLine();
            }
            else {
                char* endptr;
                temp = strtol(buffer, &endptr, 10);
                if (*endptr != '\n' && *endptr != '\0') {
                    printf("Invalid input. Input must be an integer.\n");
                    printLine();
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
                printLine();
            }
            else {
                int end_ptr;
                if (sscanf(buffer, "%lf%n", &temp, &end_ptr) != 1 || buffer[end_ptr] != '\n') {
                    printf("Invalid input. Please enter a valid double.\n");
                    printLine();
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
                printLine();
            }
            else if (strlen(buffer) > 2) {
                printf("Invalid input. Input must be a single character.\n");
                printLine();
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
                printLine();
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
                printLine();
            }
        }
    }
    else {
        printf("Invalid datatype.\n");
        printLine();
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
            printLine();
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
                printLine();
            }
        }
    }
}

//ARRAY STUFFS
void printArray(void *arr, int size) {
    char *p = (char *)arr;
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}




#endif
