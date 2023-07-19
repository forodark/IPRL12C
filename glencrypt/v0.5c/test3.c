#include <stdio.h>
#include "glencrypt.h"



typedef struct {
    char name[20];
    int age;
    double salary;
} person;

typedef struct {
    char name[20];
    char number[20];
    double balance;
    int count;
} account;

person people[] = {
    {"John", 20, 10000},
    {"Jane", 30, 20000},
    {"Bob", 40, 30000},
    {"Charlie", 50, 40000},
};

account accounts[] = {
    {"John", "1234567890", 1000, 1},
    {"Jane", "9876543210", 2000, 2},
    {"Bob", "1111111111", 3000, 3},
    {"Charlie", "2222222222", 4000, 4},
};

// table test[] = {
//     TABLE_COLUMN("Name", people, name, "char*"),
//     TABLE_COLUMN("Age", people, age, "int"),
//     TABLE_COLUMN("Salary", people, salary, "double"),
// };

table test[] = {
    TABLE_COLUMN("Name", people, name, "%s"),
    TABLE_COLUMN("Age", people, age, "%d"),
    TABLE_COLUMN("Salary", people, salary, "%lf"),
};

// table test2[] = {
//     TABLE_COLUMN("Name", accounts, name, char*),
//     TABLE_COLUMN("Number", accounts, number, char*),
//     TABLE_COLUMN("Balance", accounts, balance, double),
//     TABLE_COLUMN("Count", accounts, count, int),
//     END_TABLE
// };

int main() {
    printTable(test);
    
    // int x = 100;
    // float x = 100.2;

    // char buffer[MAX_STRING_LENGTH];

    // formatString("%f", buffer, x);

    // printf("%s\n", buffer);

    return 0;
}
