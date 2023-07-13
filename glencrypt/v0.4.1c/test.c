#include "glencrypt.h"

void function1() {
    printf("Option 1\n");
}
void function2() {
    printf("Option 2\n");
}



menu page_1[] = {
    {"Option 1", function1},
    {"Option 2", function2},
    END_MENU
};

menu page_2[] = {
    {"Option 3", function1},
    {"Option 4", function2},
    END_MENU
};

page_menu test_menu[] = {
    page_1,
    page_2,
    END_MENU
};

int main() {
    showPageMenu("Main Menu", test_menu);
    return 0;
}
