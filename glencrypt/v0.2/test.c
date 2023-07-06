#include <stdio.h>
#include <string.h>
//#include "glencrypt.h"

void printLine(int type) {
	switch(type) {
		case 0:
			printf("---------------------------------\n");
			break;
		case 1:
			printf("->->-~-~-~-=-=-=-=-=-=-~-~-~-<-<-\n");
			break;
		default:
			printf("---------------------------------\n");
			break;
	}

}


int main() {
//	for (int i = 0; i < 5; i++) {
//		char* test = generateKey(63);
//		printf("%s\n", test);
//	}
		printLine(1);
		printLine(0);
	
	while(1) {
		char test[64];

//		inputCustom("Encrypt: ", &test, CHARLIB);
//		char* encrypted = keyEncrypt(test, "hello");
//		printf("Encrypted: %s\n", encrypted);

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
