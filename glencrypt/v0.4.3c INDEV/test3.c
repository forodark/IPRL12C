#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define MAX_STRING_LENGTH 256


void convertString(void* data, char* type, char* str) {
    if (data == NULL) {
        strcpy(str, "NULL");
    } else if (!strcmp(type, "int")) {
        snprintf(str, MAX_STRING_LENGTH, "%d", *((int*)data));
    } else if (!strcmp(type, "float")) {
        snprintf(str, MAX_STRING_LENGTH, "%f", *((float*)data));
    } else if (!strcmp(type, "double")) {
        snprintf(str, MAX_STRING_LENGTH, "%.2lf", *((double*)data));
    } else if (!strcmp(type, "char*")) {
        snprintf(str, MAX_STRING_LENGTH, "%s", (char*)data);
    } else {
        strcpy(str, "Unknown Type"); // Handle unknown types
    }
}

typedef struct {
    char* header;
    void** content;
    size_t content_size;  // Change to 'num_elements'
    size_t offset;
    size_t struct_size;  // Add the size of the structure
    char* data_type;     // Add the data type of the column
} table;


#define END_TABLE {NULL, NULL, 0, 0, 0, NULL}

void printTable(table* table) {
    int num_columns = 0;
    while (table[num_columns].header != NULL) {
        num_columns++;
    }

    // Print table headers
    for (int i = 0; i < num_columns; i++) {
        printf("%s\t", table[i].header);
    }
    printf("\n");

    // Print table content
    for (int i = 0; i < table->content_size; i++) {
        for (int j = 0; j < num_columns; j++) {
            char buffer[MAX_STRING_LENGTH];
            convertString((char*)((uintptr_t)table[j].content + table[j].offset) + (i * table[j].struct_size), table[j].data_type, buffer);
            printf("%s\t", buffer);
        }
        printf("\n");
    }
}


typedef struct {
    char name[20];
    int age;
    double salary;
} person;

person people[] = {
    {"John", 20, 10000},
    {"Jane", 30, 20000},
    {"Bob", 40, 30000},
    {"Charlie", 50, 40000},
};

table test[] = {
    {"Name", (void**)&people, sizeof(people) / sizeof(people[0]), offsetof(person, name), sizeof(people[0]), "char*"},
    {"Age", (void**)&people, sizeof(people) / sizeof(people[0]), offsetof(person, age), sizeof(people[0]), "int"},
    {"Salary", (void**)&people, sizeof(people) / sizeof(people[0]), offsetof(person, salary), sizeof(people[0]), "double"},
    END_TABLE
};


int main() {
    printTable(test);

    // printf("%zu\n", offsetof(person, age));
    // printf("%zu\n", offsetof(people[0], age));
    // printf("%zu\n", sizeof(people) / sizeof(people[0]));

    return 0;
}
