#include <stdio.h>
#include "../glencrypt.h"


void FPQuiz() {
    FILE *input_file = openFile("text/", "data.txt", "r");
    
   	if (input_file == NULL) {
		printf("ERROR: data.txt cannot be opened.\n");
		exit(1);
	}
    
    int uppercase_count = 0;
	char c;
	
	while ((c = fgetc(input_file)) != EOF) {
		if(c >= 'A' && c <= 'Z')
		uppercase_count++;
	}    
    printColor(GREEN, "Uppercase letters in data.txt: %d\n", uppercase_count);
	fclose(input_file);
}
