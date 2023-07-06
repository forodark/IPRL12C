#ifndef GLENCRYPT_H
#define GLENCRYPT_H

#include <stdio.h>
#include <string.h>

const char* encrypt(char input[]) {
    static char output[100]; 
    int n = strlen(input);
    
    for(int i = 0; i < n; i++) {
        output[i] = (char)((input[i]*2)-23-i);
    }
    output[n] = '\0'; 
    
    return output;
}

const char* decrypt(char input[]) {
    static char output[100]; 
    int n = strlen(input);
    
    for(int i = 0; i < n; i++) {
        output[i] = (char)((input[i]+23+i)/2);
    }
    output[n] = '\0';
    
    return output;
}

#endif