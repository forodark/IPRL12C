#include <stdio.h>
#include <stddef.h>





typedef struct {
    char name[20];
    int age;
    int salary;
} person;

#define END_STRUCT {NULL, NULL, NULL}

void printMember(person* people, int numPeople, size_t memberOffset) {
    for (int i = 0; i < numPeople; i++) {
        char memberStr[20];
        void* member = (void*)((char*)&people[i] + memberOffset);

        if (member == NULL) {          
            break;

        }

        if (memberOffset == offsetof(person, age)) {
            snprintf(memberStr, sizeof(memberStr), "%d", *((int*)member));
        } else if (memberOffset == offsetof(person, salary)) {
            snprintf(memberStr, sizeof(memberStr), "%d", *((int*)member));
        } else {
            snprintf(memberStr, sizeof(memberStr), "%s", (char*)member);
        }

        printf("memberOffset: %d, member: %s\n", memberOffset, memberStr);

        printf("%s\n", memberStr);
    }
}

int main() {
    person people[] = {
        {"John", 20, 10000},
        {"Jane", 30, 20000},
        {"Bob", 40, 30000},
        END_STRUCT
    };

    int numPeople = sizeof(people) / sizeof(people[0]);

    // Print the names
    printf("Names:\n");
    printMember(people, numPeople, offsetof(person, name));

    // Print the ages
    printf("Ages:\n");
    printMember(people, numPeople, offsetof(person, age));

    // Print the salaries
    printf("Salaries:\n");
    printMember(people, numPeople, offsetof(person, salary));

    return 0;
}