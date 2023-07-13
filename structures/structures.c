#include <stdio.h>
#include "glencrypt.h"

void example1();
void example2();
void example3();
void example4();
void showMenu();

int main() {
    showMenu();
    return 0;

}


void showMenu() {//menu
    while(1) {
		system("cls");
		printLine(0);
		printf("Structures Examples\n");
		printLine(0);
	    printf("[1] Example 1\n");
	    printf("[2] Example 2\n");
	    printf("[3] Example 3\n");
	    printf("[4] Example 4\n");
		printf("[0] Exit\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	example1();
				break;
			case 2:
            	example2();
				break;
			case 3:
				example3();
				break;
			case 4:
				example4();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	}
}

void example1() {
    struct
    {
        int x;
        int y;
    } point;

    point.x = 1; point.y = 2;

    printf("point.x = %d\n", point.x);
    printf("point.y = %d\n", point.y);
}

void example2() {
    struct
    {
        char name[40];
        int idnumber;
        char course[10];
    } student;

    strcpy(student.name, "Glen");
    student.idnumber = 1234;
    strcpy(student.course, "Computer Science");
    printf("student.name = %s\n", student.name);
    printf("student.idnumber = %d\n", student.idnumber);
    printf("student.course = %s\n", student.course);
}

void example3() {
    struct pointType // point structure template
    {
        int x;
        int y;
    };
    // declare the actual structure variable
    struct pointType point;

    point.x = 1; point.y = 2;

    printf("point.x = %d\n", point.x);
    printf("point.y = %d\n", point.y);
}

void example4() {
    struct studentType    // student structure template
    {
        char name[40];
        int idnumber;
        char course[10];
    };
    // declare actual structure variable
    struct studentType student;

    strcpy(student.name, "Glen");
    student.idnumber = 1234;
    strcpy(student.course, "Computer Science");
    printf("student.name = %s\n", student.name);
    printf("student.idnumber = %d\n", student.idnumber);
    printf("student.course = %s\n", student.course);
}