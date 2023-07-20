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

form test[] = {
    FORM_FIELD("Enter ID: ", people, id, "%d"),
    FORM_FIELD("Enter Name: ", people, name, "%s"),
    END_FORM
};

table test2[] = {
    TABLE_COLUMN("ID", people, id, "%-6d"),
    TABLE_COLUMN("Name", people, name, "%-16s"),
    END_TABLE
};

int main() {
    // showForm("Test Form", test);

    people[2].id = 3;
    strcpy(people[2].name, "Bob");

    // // size_t num_people = sizeof(people) / sizeof(people[0]);

    // Print the elements of the 'people' array
    for (size_t i = 0; i < test2->content_size + 1; i++) {
        printf("ID: %d, Name: %s\n", people[i].id, people[i].name);
    }
    size_t num_people = sizeof(people) / sizeof(people[0]);
    printf("Number of people: %zu\n", num_people);

    // printTableFull("Test", test2);

    return 0;
}