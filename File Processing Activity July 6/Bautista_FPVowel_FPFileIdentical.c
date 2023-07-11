#include <stdio.h>
#include "glencrypt.h"

void FPVowel();
void FPFileIdentical();
void showMenu();

int main() { 
	showMenu();
	return 0;
}

void showMenu() { //menu
	while(1) {
		printLine(0);
		printf("File Processing Activity - July 6\n");
		printLine(3);
	    printf("[1] FPVowel - Count number of vowels\n");
	    printf("[2] FPFileIdentical - Check if two files are identical\n");
		printf("[0] Exit\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	FPVowel();
				printLine(0);
				break;
			case 2:
            	FPFileIdentical();
				printLine(0);
				break;
			case 0:
				printf("Exiting Program...\n");
				waitEnter();
				exit(0);
				break;
			default:
				printColor(RED, "Invalid choice.\n");
				waitEnter();
		}
	waitEnter();
	system("cls");
	}
}

void FPVowel() {
     //Write a program that will count the number of vowel letters in a text file.
	 
	 char input_file_name[] = "input.txt";
     FILE *input = fopen(input_file_name, "r");;
     char ch;
     int count = 0;
     if (input == NULL) {
          printColor(RED, "Error opening file.\n");
          return;
     }
     while ((ch = fgetc(input)) != EOF) {
          if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
               count++;
     }
     fclose(input);
     printColor(GREEN, "There are %d vowels in %s\n", count, input_file_name);
}

void FPFileIdentical() {
	//Assume that there are two text files.  Write a program that will determine 
	//whether these two text files are identical or not (i.e., the contents are the same). 
	
    char input_file_name[] = "input.txt";
    char input2_file_name[] = "input2.txt";
    
    FILE *input = fopen(input_file_name, "r");
    FILE *input2 = fopen(input2_file_name, "r");

    if (input == NULL || input2 == NULL) {
        printColor(RED, "Error opening files.\n");
        return;
    }

    int ch1, ch2;
    int identical = 1;

    while ((ch1 = fgetc(input)) != EOF && (ch2 = fgetc(input2)) != EOF) {
        if (ch1 != ch2) {
            identical = 0;
            break;
        }
    }

    if (!identical && !(ch1 == EOF && ch2 == EOF)) {
        printColor(RED, "Files are not identical.\n");
    }
    else {
        printColor(GREEN, "Files are identical.\n");
    }

    fclose(input);
    fclose(input2);
}

