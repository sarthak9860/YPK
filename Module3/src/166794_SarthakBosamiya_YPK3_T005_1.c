// Question 

/** REQUIRED HEADER FILES **/

#include<stdio.h>
#include"../include/head.h"

/*
 * Name of the function: xstrchr
 * Author: Sarthak Bosamiya
 * Created: 03-03-2025
 * Modified: 03-03-2025
*/

char *xstrchr(char *s, char ch){
        for (int i=0; s[i]!='\0'; i++){
                if (*(s+i)==ch){
                        return s+i;
                }
        }
        return NULL;
}

void exe1(){
	char s[]="Hello";
        char ch='l';
        char* p = xstrchr(s,ch);
        printf("Character %c is found in string %s\n",*p,s);
}
