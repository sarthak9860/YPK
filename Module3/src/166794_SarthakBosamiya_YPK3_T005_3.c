// Question 

/** REQUIRED HEADER FILES **/

#include<stdio.h>
#include<string.h>
#include"../include/head.h"

/*
 * Name of the function:  
 * Author: Sarthak Bosamiya
 * Created: 03-03-2025
 * Modified: 03-03-2025
*/

void arrange(char *names[], int n) {
    	for (int i = 0; i < n - 1; i++) {
        	for (int j = 0; j < n - i - 1; j++) {
            		if (strcmp(names[j], names[j + 1]) > 0) {
                		char *temp = names[j];
                		names[j] = names[j + 1];
                		names[j + 1] = temp;
            		}
        	}
    	}
}

void exe3() {
    	char *names[] = {"Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"};
    	int n = sizeof(names) / sizeof(names[0]);
    	arrange(names, n);
    	for (int i = 0; i < n; i++) {
        	printf("%s\n", names[i]);
    	}
}

