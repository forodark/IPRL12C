
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "glencrypt.h"


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
    TABLE_COLUMN("Name", people, name, "%s"),
    TABLE_COLUMN("Age", people, age, "%d"),
    TABLE_COLUMN("Salary", people, salary, "%.2lf"),
};

int main() {
    printTable(test);
    return 0;
}