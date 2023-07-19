
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "glencrypt.h"

#define TABLE_PAGE_LENGTH 10

void printPageTable(char* title, table* table) {
    int num_columns = 0;
    while (table[num_columns].header != NULL) {
        num_columns++;
    }

    int page = 0; 
    int max_page = ((table->content_size) / TABLE_PAGE_LENGTH);
    int page_row_counter = 0; int table_row_counter = 0;

    while(1) {
        system("cls");
        // Print table title
        int table_width = (num_columns*2)+1;
        for (int i = 0; i < num_columns; i++) {
            table_width += extractNumber(table[i].format);
        }
        printLineWidth(table_width);
        printCentered(title, table_width);
        printf("\n");
        printLineWidth(table_width);

        // Print table headers
        printf("|");
        for (int i = 0; i < num_columns; i++) {
            int column_width = extractNumber(table[i].format) + 1;
            printCentered(table[i].header, column_width);
            printf("|");
        }
        printf("\n");

        // Print table content
        for (; page_row_counter < TABLE_PAGE_LENGTH && table_row_counter < table->content_size; page_row_counter++, table_row_counter++) {
            printf("|");
            for (int j = 0; j < num_columns; j++) {
                char buffer[MAX_STRING_LENGTH];
                formatString((char*)((uintptr_t)table[j].content + table[j].offset) + (table_row_counter * table[j].struct_size), typeFromFormat(table[j].format), buffer, table[j].format);
                // convertString((char*)((uintptr_t)table[j].content + table[j].offset) + (table_row_counter * table[j].struct_size), table[j].format, buffer); //this line is killing me
                printf(" %s|", buffer);
            }
            printf("\n");
        }
        page_row_counter = 0;

        printLineWidth(table_width);

        printf(" Page %d/%d    ", page+1, max_page+1);
        if (page > 0) {
            printf("[8] Previous Page    ");
        }
        if (page != max_page) {
            printf("[9] Next Page    ");
        }
        printf("[0] Return\n");

        printLineWidth(table_width);

        int choice;
        input(Int, "Enter choice: ", &choice);
        switch (choice) {
            case 8:
                if (page > 0) {	
                    page--;
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    break;
                }
                else {
                    invalidChoiceCustom("Invalid choice.", table_width);
                    continue;
                }
                
            case 9:
                if (page != max_page) {	
                    page++;
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    break;
                }
                else {
                    invalidChoiceCustom("Invalid choice.", table_width);
                    continue;
                }
            case 0:
                printLine(2);
                return;
                break;
            default:
                invalidChoiceCustom("Invalid choice.", table_width);
                continue; 
        }
    }
}

typedef struct {
    int id;
    char name[20];
    int age;
    double salary;
} person;

person people[] = {
    {1, "John", 20, 10000},
    {2, "Jane", 30, 20000},
    {3, "Bob", 40, 30000},
    {4, "Charlie", 50, 40000},
    {5, "David", 60, 50000},
    {6, "Emily", 70, 60000},
    {7, "Frank", 80, 70000},
    {8, "George", 90, 80000},
    {9, "Helen", 100, 90000},
    {10, "Irene", 110, 100000},
    {11, "Jack", 120, 110000},
    {12, "Jessica", 130, 120000},
    {13, "Katie", 140, 130000},
    {14, "Linda", 150, 140000},
    {15, "Mia", 160, 150000},
};

table test[] = {
    TABLE_COLUMN("ID", people, id, "%-6d"),
    TABLE_COLUMN("Name", people, name, "%-16s"),
    TABLE_COLUMN("Age", people, age, "%-6d"),
    TABLE_COLUMN("Salary", people, salary, "%-20.2lf"),
    END_TABLE
};

int main() {
    printPageTable("Test Table", test);
    return 0;
}