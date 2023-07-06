#include <stdio.h>
#include <string.h>
#include "glencrypt.h"



int main() {
//	for (int i = 0; i < 5; i++) {
//		char* test = generateKey(63);
//		printf("%s\n", test);
//	}
	printLine(2);
	while(1) {
		char test[64];

		inputCustom("Encrypt: ", &test, CHARLIB);
		char* encrypted = encrypt(test);
		printf("Encrypted: %s\n", encrypted);
		
		printLine(0);
		

//		char* decrypted = decrypt(encrypted);
//		printf("Decrypted: %s\n", decrypted);
//	
//		char str[64];
//		char ch;
//		input(STR, "Enter str: ", &str);
//		input(CHAR, "Enter char: ", &ch);
//		printf("'%c' was found at position %d in the string.\n", ch, getCharPos(str, ch));



	}

	
}
