// Question 

/** REQUIRED HEADER FILES **/

#include<stdio.h>
#include"../include/head.h"
#include <string.h>
#define MAX_LEN 1000

/*
 * Name of the function:  
 * Author: Sarthak Bosamiya
 * Created: 03-03-2025
 * Modified: 03-03-2025
*/

void compressString(char *input, char *compressed) {
    	int i = 0, j = 0;
    	while (input[i] != '\0') {
        	if (input[i] == ' ') {
            		compressed[j++] = ' ';
            		while (input[i] == ' ') {
                		i++;
            		}
        	}		 
		else {
            		compressed[j++] = input[i++];
        	}
    	}
    	compressed[j] = '\0';
}

void decompressString(char *compressed, char *decompressed) {
    	int i = 0, j = 0;
    	while (compressed[i] != '\0') {
        	decompressed[j++] = compressed[i];
        	if (compressed[i] == ' ') {
            		decompressed[j++] = ' ';
        	}
        	i++;
    	}
    	decompressed[j] = '\0';
}

void exe4() {
    	char original[MAX_LEN] = "Hello   this is a    Line for     cheking compressing    and decompressing   of the   string.";
    	char compressed[MAX_LEN];
    	char decompressed[MAX_LEN];
    	compressString(original, compressed);
    	printf("Original String:\n%s\n\n", original);
    	printf("Compressed String (without extra spaces):\n%s\n\n", compressed);
    	decompressString(compressed, decompressed);
    	printf("Decompressed String:\n%s\n", decompressed);
}
