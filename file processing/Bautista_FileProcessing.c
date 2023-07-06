#include <stdio.h>
#include <stdlib.h>
#include "glencrypt.h"

void showMenu();
void example1();
void example2();
void example3();
void example4();
void example5();

int main() {
	showMenu();
	return 0;
}


void showMenu() {
    while(1) {
    	int choice;
		printf("Examples on File Processing\n");
		printLine(0);
	    printf("[1] Part 4 - Example 1\n");
	    printf("[2] Part 4 - Example 2\n");
	    printf("[3] Part 5 - Example 1\n");
	    printf("[4] Part 6 - Example 2\n");
	    printf("[5] Part 6 - Example\n");;	    
		printf("[0] Exit\n");
	    printLine(0);
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch(choice) {
			case 1:
            	example1();
				printLine(0);
				break;
			case 2:
            	example2();
				printLine(0);
				break;
			case 3:
				example3();
				printLine(0);
				break;
			case 4:
				example4();
				printLine(0);
				break;
			case 5:
				example5();
				printLine(0);
				break;
			case 0:
				printf("Exiting Program...\n");
				exit (0);	
				break;
			default:
				printf("Invalid choice.\n");
		}
		waitEnter();
		system("CLS");
	}
}

void example1() {
	FILE *inputf;
	int c;
	
	// Open text file for input
	if ((inputf = fopen("test.txt", "r")) == NULL) {
		printf("ERROR: test.txt cannot be opened.\n");
		exit(1);
	}
	
	// Read one character at a time from file, output onto screen
	// Repeat until the end-of-file character is met
	while ((c = fgetc(inputf)) != EOF) {
		printf("%c", c);
	}
	printf("\n");
	fclose(inputf);
}


void example2() {
	FILE *inputf;
	int c;
	char filename[40];
	// Get the name of the text file to open.
	input(Str, "Input name of text file: ", &filename); //replaced with custom input function
	
	if ((inputf = fopen(filename, "r")) == NULL) {
		printf("ERROR: %s cannot be opened.\n", filename);
		exit(1);
	}
	
	while ((c = fgetc(inputf)) != EOF) {
		printf("%c", c);
	}
	printf("\n");
	fclose(inputf);

}

void example3() { 
	FILE *inputf;
	char filename[40];
	int c;
	
	// Get the name of the text file to open.
	input(Str, "Input name of text file: ", &filename);  //replaced with custom input function
	
	// Open the file for input.
	if ((inputf = fopen(filename, "r")) == NULL) {
		// The file could not be opened.
		printf("ERROR: %s cannot be opened.\n", filename);
		exit(1);
	}
	
	// Read one character at a time from the file and output it to stdout.
	while ((c = fgetc(inputf)) != EOF) {
		fputc(c, stdout);
	}
	printf("\n");
	// Close the file.
	fclose(inputf);

}

void example4() {
	FILE *inputf, *outputf;
	char inputfilename[40], outputfilename[40];
	int c;
	
	// Get the name of the input text file.
	input(Str, "Input name of input text file: ", &inputfilename);
	
	// Open the input file.
	if ((inputf = fopen(inputfilename, "r")) == NULL) {
		// The input file could not be opened.
		printf("ERROR: %s cannot be opened.\n", inputfilename);
		exit(1);
	}
	
	// Get the name of the output text file.
	input(Str, "Input name of output text file: ", &outputfilename);
	
	// Open the output file.
	outputf = fopen(outputfilename, "w");
	
	// Read one character at a time from the input file and write it to the output file.
	while ((c = fgetc(inputf)) != EOF) {
		fputc(c, outputf);
	}
	printf("Successfully copied contents of %s to %s\n", inputfilename, outputfilename); //added confirmation text 		
	// Close the files.
	fclose(inputf);
	fclose(outputf);


}

void example5() {
	FILE *outputf;
	char outputfilename[40];
	char ch;
	int i;
	float f;
	double d;
	
	// Initialize variables.
	ch = 'A';
	i = 100;
	f = 88.3;
	d = 3.1416;
	
	// Ask for filename and open text file for output.
	input(Str, "Input name of output text file: ", &outputfilename);
	outputf = fopen(outputfilename, "w");
	
	// Output formatted data onto text file.
	fprintf(outputf, "ch = %c\n", ch);
	fprintf(outputf, "i = %d\n", i);
	fprintf(outputf, "f = %f\n", f);
	fprintf(outputf, "d = %lf\n", d);
	fprintf(outputf, "Goodbye!\n");
	
	// Close the file.
	fclose(outputf);


}
