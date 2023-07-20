
#include <stdio.h>
#include <string.h>
#include "glencrypt.h"



typedef struct {
    int id;
    char name[20];
} person;

person people[MAX_ELEMENTS] = {
    {1, "John"},
    {2, "Jane"},
    {3, "Bob"}
};


int countStructElements(const void* content, size_t struct_size) {
    int count = 0;
    while (count < MAX_ELEMENTS && *(content + (count * struct_size)) != NULL && ) {
        count++;
    }
    return count;
}

int main() {

    printf("%d", countStructElements(people, sizeof(person)));

    return 0;
}
