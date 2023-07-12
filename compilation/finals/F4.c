#include <stdio.h>
#include "../glencrypt.h"

void Finals_MP3();
void Finals_MP4();

//Write a program that will ask the user to input two integers, say n1 and n2.  
//The second integer should be greater than the second integer, i.e., n1 < n2.  
//Thereafter, the program should output to a text file the integers from n1 to n2 
//(i.e., n1, n1 + 1, �, n2-1, n2).  Output one integer per line.
void Finals_MP3() {
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
void Finals_MP4() {
	system("cls");
	printLine(0);
	printf("MP4 - Read File\n");
	printLine(0);
	int n;
	char file_name[] = "output.txt";
	FILE *input_file = fopen(file_name, "r");
	
	if (input_file == NULL) {
		printColor(RED, "Error: %s cannot be opened.\n", file_name);
		return;
	}
	
	while ((n = fgetc(input_file)) != EOF) {
		fputc(n, stdout);
	}
}
