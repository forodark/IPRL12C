#include <stdio.h>
#include "../glencrypt.h"

void M3example1();
void M3example2();
void M3example3();
void M3example4();

void M3example1() {
    struct
    {
        int x;
        int y;
    } point;

    point.x = 1; point.y = 2;

    printf("point.x = %d\n", point.x);
    printf("point.y = %d\n", point.y);
}

void M3example2() {
    struct
    {
        char *name;
        int idnumber;
        char *course;
    } student;

    strcpy(student.name, "Glen");
    student.idnumber = 1234;
    strcpy(student.course, "Computer Science");
    printf("student.name = %s\n", student.name);
    printf("student.idnumber = %d\n", student.idnumber);
    printf("student.course = %s\n", student.course);
}

void M3example3() {
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

void M3example4() {
    struct studentType    // student structure template
    {
        char *name;
        int idnumber;
        char *course;
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