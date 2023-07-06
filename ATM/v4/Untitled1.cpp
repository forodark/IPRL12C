#include <stdio.h>
#include "glencrypt.h"

int main() {
	
	while(1) {
	
	char input[64];
	
	inputCustom("encrypt: ", &input, ALPHANUM);
	
	printf("output: %s\n", encrypt(input));
		
	}
	return 0;
}