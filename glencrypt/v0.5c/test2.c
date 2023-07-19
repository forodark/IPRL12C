#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "glencrypt.h"

#define MAX_STRING_LENGTH 256

#define getDataType(x) _Generic((x), \
    int:     "int", \
    float:   "float", \
    double:  "double", \
    char*:   "char*", \
    void*:   "void*", \
    size_t:  "size_t", \
    int*:    "int*", \
    float*:  "float*", \
    double*: "double*", \
    default: "other")

void convertString(void* data, char* type, char* str) {
    if (data == NULL) {
        strcpy(str, "NULL");
    }
    else if (!strcmp(type, "int")) {
        snprintf(str, MAX_STRING_LENGTH, "%d", *((int*)data));
    }
    else if (!strcmp(type, "float")) {
        snprintf(str, MAX_STRING_LENGTH, "%f", *((float*)data));
    }
    else if (!strcmp(type, "double")) {
        snprintf(str, MAX_STRING_LENGTH, "%lf", *((double*)data));
    }
    else if (!strcmp(type, "char*")) {
        snprintf(str, MAX_STRING_LENGTH, "%s", (char*)data);
    }
    else {
        snprintf(str, MAX_STRING_LENGTH, "%p", data);
    }
}

void printType(void* data, char* type) {
    if (data == NULL) {
        printf("NULL\n");
    }
    else if (!strcmp(type, "int")) {
        printf("%d\n", *((int*)data));
    }
    else if (!strcmp(type, "float")) {
        printf("%f\n", *((float*)data));
    }
    else if (!strcmp(type, "double")) {
        printf("%lf\n", *((double*)data));
    }
    else if (!strcmp(type, "char*")) {
        printf("%s\n", (char*)data);
    }
    else {
        printf("%p\n", data);
    }
}

typedef struct {
    char* header;
    void* content;
    size_t content_size;
    size_t offset;
} table;

#define END_TABLE {NULL, NULL}

void printTable(table* table) {
    for(int i = 0; table[i].header != NULL; i++) {
        printf("%s\t", table[i].header);
    }
    printf("\n");
    for(int i = 0; table[i].header != NULL; i++) {
        for(int j = 0; table[j].header != NULL; j++) {
            char buffer[256];
            // void *member = (char*)((uintptr_t)table[j].content + table[j].offset) + (i * table[j].content_size);
            // convertString((char*)table[j].content + table[j].offset, buffer);
            convertString((char*)((uintptr_t)table[j].content + table[j].offset) + (i * table[j].content_size), "char*", buffer);


            printf("%s\n", buffer);
        }
    }
}

// void printTableD(table* table) {
//     for(int i = 0; table[i].header != NULL; i++) {
//         printf("%s\t", table[i].header);
//     }
//     printf("\n");
//     char buffer[256];
//     convertString((char*)table[0].content + table[0].offset, buffer);
//     // convertString((char*)((uintptr_t)table[j].content + table[j].offset) + (i * table[j].content_size), buffer);
// }



//--------------------------------------------

typedef struct {
    char name[20];
    int age;
    double salary;
} person;

person people[] = {
    {"John", 20, 10000},
    {"Jane", 30, 20000},
    {"Bob", 40, 30000}
};


table test[] = {
    {"Name", &people, sizeof(person), offsetof(person, name)},
    {"Age", &people, sizeof(person), offsetof(person, age)},
    {"Salary", &people, sizeof(person), offsetof(person, salary)},
    END_TABLE
};

//----------------------------------------------

int main() {
    printTable(test);

    // int i = 10;
    // int *pi = &i;

    // printf("%s\n", getDataType(i));
    // printf("%s\n", getDataType(pi));
    // printf("%s\n", getDataType(*pi));

    return 0;
}