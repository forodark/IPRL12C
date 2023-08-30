#include <stdio.h> 
#include "glencrypt.h"

typedef struct {
    int id;
    char name[20];
} person;

person people[] = {
    {1, "John"},
    {2, "Jane"}
};


table test2[] = {
    TABLE_COLUMN("ID", people, id, "%-6d"),
    TABLE_COLUMN("Name", people, name, "%-16s"),
    END_TABLE
};

int main() {
while(1) {
    inputForm("Test Form", test2);
    }
    return 0;
}