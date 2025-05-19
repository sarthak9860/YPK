// Question 

/** REQUIRED HEADER FILES **/

#include<stdio.h>
#include"../include/head.h"

/*
 * Name of the function:  
 * Author: Sarthak Bosamiya
 * Created: 24-04-2025
 * Modified: 24-04-2025
*/

int main(){
	int n;
	printf("Enter the number of exercise you want to execute: ");
	scanf("%d", &n);
	switch(n){
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		default:
			printf("Enter the valid number\n");
			break;
	}
}
