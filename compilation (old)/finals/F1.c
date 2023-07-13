#include <stdio.h>
#include <stdlib.h>
#include "../glencrypt.h"


void example1F1();
void example2F1();
void example3F1();
void example4F1();
void example5F1();

void example1F1() {
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


void example2F1() {
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

void example3F1() { 
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

void example4F1() {
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

void example5F1() {
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
