#include "glencrypt.h"

void function1() {
    printf("Option 1\n");
}
void function2() {
    printf("Option 2\n");
}



menu options[] = {
    {"Option 1", function1},
    {"Option 2", function2},
    END_MENU
};

int main() {
    showMenu("Main Menu", options);
    return 0;
}
