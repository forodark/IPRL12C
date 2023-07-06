#include <stdio.h>
#include "glencrypt.h"

void MP3();
void MP4();

int main() { //menu
    while(1) {
		printLine(0);
		printf("File Processing Machine Problems\n");
		printLine(0);
	    printf("[1] MP3 - Numbers n1 to n2\n");
	    printf("[2] MP4 - Read File\n");
		printf("[0] Exit\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	MP3();
				printLine(0);
				break;
			case 2:
            	MP4();
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

//Write a program that will ask the user to input two integers, say n1 and n2.  
//The second integer should be greater than the second integer, i.e., n1 < n2.  
//Thereafter, the program should output to a text file the integers from n1 to n2 
//(i.e., n1, n1 + 1, …, n2-1, n2).  Output one integer per line.
void MP3() {
	system("cls");
	printLine(0);
	printf("MP3 - Numbers n1 to n2\n");
	printLine(0);
	int n1, n2;
	char file_name[] = "output.txt";
	input(Int, "Enter first integer: ", &n1);
	
	while(1) {
		input(Int, "Enter second integer: ", &n2);
		if (n1 < n2) { break; }
		printColor(RED, "The second integer must be greater than the first integer.\n");
		printColor(RED, "%d </ %d\n", n1, n2);
		printLine(0);
	}

	printLine(0);
	FILE *output_file = fopen(file_name, "w");
	for (int i = n1; i <= n2; i++) {
		fprintf(output_file, "%d\n", i);	
	}
	fclose(output_file);
	printColor(GREEN, "Program run successfully.\nOutput in %s\n", file_name);
}

//Write a program that will read the integers from the file generated in the previous exercise. 
//The program should also print the integers onto the standard output device.
void MP4() {
	system("cls");
	printLine(0);
	printf("MP4 - Read File\n");
	printLine(0);
	int n;
	char file_name[] = "output.txt";
	FILE *input_file = fopen(file_name, "r");
	
	if (input_file == NULL) {
		printColor(RED, "Error: %s cannot be opened.\n", file_name);
		main();
	}
	
	while ((n = fgetc(input_file)) != EOF) {
		fputc(n, stdout);
	}
}
