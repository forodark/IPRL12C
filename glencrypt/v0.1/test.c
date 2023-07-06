#include <stdio.h>
#include <string.h>
#include "glencrypt.h"

#define CHARLIB "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .!?@_"
#define DEFAULTKEY "qwertyuiop_123"

int getCharPos(char* str, char ch) {
    char* pos = strchr(str, ch);
    if (pos == NULL) {
        return -1;
    }
	else {
        return (int)(pos - str);
    }
}


const char* encryptv2(char input[], char key[]) {
    static char output[256];
    int converted_input[256];
    int converted_key[256];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] + converted_key[x]) % 66;
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}

const char* decryptv2(char input[], char key[]) {
    static char output[256];
    int converted_input[256];
    int converted_key[256];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] - converted_key[x] + 66) % 66;
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}

const char* encrypt2(char input[]) {
    static char output[256];
    char key[] = DEFAULTKEY;
    int converted_input[256];
    int converted_key[256];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] + converted_key[x]) % 68;
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}

const char* decrypt2(char input[]) {
    static char output[256];
    char key[] = DEFAULTKEY;
    int converted_input[256];
    int converted_key[256];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] - converted_key[x] + 68) % 68;
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}


int main() {
	while(1) {
		char test[64];

		inputCustom("Encrypt: ", &test, CHARLIB);
		char* encrypted = encrypt(test);
		printf("Encrypted: %s\n", encrypted);
		char* decrypted = decrypt(encrypted);
		printf("Decrypted: %s\n", decrypted);
	


//		char str[64];
//		char ch;
//		input(STR, "Enter str: ", &str);
//		input(CHAR, "Enter char: ", &ch);
//		printf("'%c' was found at position %d in the string.\n", ch, getCharPos(str, ch));
//	
	}
	
	
}
