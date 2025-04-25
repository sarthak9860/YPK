// Question 

/** REQUIRED HEADER FILES **/

#include<stdio.h>
#include"../include/head.h"
#include <string.h>
#define KEY 0x5A // A secret key for encryption and decryption

/*
 * Name of the function:  
 * Author: Sarthak Bosamiya
 * Created: 03-03-2025
 * Modified: 03-03-2025
*/

void encrypt(char *input, char *output) {
    	int len = strlen(input);
    	for (int i = 0; i < len; i++) {
        	output[i] = input[i] ^ (KEY + i);
    	}
    	output[len] = '\0';
}

void decrypt(char *input, char *output) {
    	int len = strlen(input);
    	for (int i = 0; i < len; i++) {
        	output[i] = input[i] ^ (KEY + i);
    	}
    	output[len] = '\0';
}

void exe5(){
    	char original[256];
    	char encrypted[256];
    	char decrypted[256];
    	printf("Enter a string to encrypt: ");
    	scanf(" %[^\n]",original);
    	encrypt(original, encrypted);
    	printf("Encrypted: ");
    	for (int i = 0; i < strlen(encrypted); i++) {
        	printf("%02X", (unsigned char)encrypted[i]);
    	}
    	printf("\n");
    	decrypt(encrypted, decrypted);
    	printf("Decrypted: %s\n", decrypted);
}
