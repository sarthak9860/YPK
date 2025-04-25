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

char *xstrstr(char *string1, char *string2) {
        if (*string2 == '\0') {
                return string1;
        }
        while (*string1 != '\0') {
                char *s1 = string1;
                char *s2 = string2;
                while (*s1 == *s2 && *s2 != '\0') {
                        s1++;
                        s2++;
                }
                if (*s2 == '\0') {
                        return string1;
                }
                string1++;
        }
        return NULL;
}

void exe2(){
        char str1[100], str2[100];
        printf("Enter the main string: ");
        scanf(" %[^\n]", str1);
        printf("Enter the substring to search: ");
        scanf(" %[^\n]", str2);
        char *result = xstrstr(str1, str2);
        if (result) {
                printf("Substring found at position: %ld\n", result - str1);
                printf("Substring starts from: %s\n", result);
        }
        else {
                printf("Substring not found.\n");
        }
}
