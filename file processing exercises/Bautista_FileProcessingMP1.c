#include <stdio.h>
#include "glencrypt.h"

int main() {
    FILE *outputf;
    char outputfilename[40];
//    char c = 'A';

    input(Str, "Input name of output text file: ", outputfilename);
    outputf = fopen(outputfilename, "w");
    
//	for(char i = 'A'; i <= 'Z'; i++) {
	for(int i = 0; i < 26; i++) {
		fprintf(outputf, "%c\n", i+65);	
	}
	printf("Program run successfully.\nOutput in %s", outputfilename);
	fclose(outputf);
	return 0;
}
