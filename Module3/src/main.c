// Question 

/** REQUIRED HEADER FILES **/

#include<stdio.h>
#include"../include/head.h"

/*
 * Name of the function:  
 * Author: Sarthak Bosamiya
 * Created: 03-03-2025
 * Modified: 03-03-2025
*/

int main(){
	int num;
	printf("Enter the number of the exercise you want to execute: ");
	scanf("%d", &num);
	switch(num){
		case 1:
			/* Question1
			 * Function Name: exe1
			 * Pointer function version of finding char in string.
			 */
			exe1();
			break;
		case 2:
			/* Quesion2
			 * Function Name: exe2
			 * Search for the substring in the main string
			 */
			exe2();
			break;
		case 3:
			/* Question3
			 * Function Name: exe3
			 * Arranges the names in alphabetical order
			 */
			exe3();
			break;
		case 4:
			/* Question4
			 * Function Name: exe4
			 * Compresses and Decompresses the string.
			 */
			exe4();
			break;
		case 5:
			/* Question5
			 * Function name: exe5
			 * Encryption and Dycription
			 */
			exe5();
			break;
		default:
			printf("Enter valid number\n");
			break;
	}
	return 0;
}
