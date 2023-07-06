#include <stdio.h>

void main(void) {
    FILE *inputf;
    char filename[40];
    int c;
    
	printf("Input name of text file:");
    scanf("%s", filename);
    // open file for input         
    if ( (inputf = fopen(filename, "r")) == NULL) {
    	printf("ERROR: %s cannot be opened.\n", filename);
    	exit(1);
    }
    // read one character at a time, output onto stdout
    while ( (c = fgetc(inputf)) != EOF ) 
        fputc(c, stdout);
	fclose(inputf);
}
