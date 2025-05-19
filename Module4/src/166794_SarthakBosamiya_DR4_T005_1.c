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

#include <stdlib.h>

int determinant(int **matrix, int n) {
	if (n == 1)
		return matrix[0][0];  // Base case for 1x1 matrix

	int det = 0;
	int sign = 1;

	int **minor = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
		minor[i] = (int *)calloc(n, sizeof(int));

	for (int col = 0; col < n; col++) {
		int subi = 0;
		for (int i = 1; i < n; i++) {
			int subj = 0;
			for (int j = 0; j < n; j++) {
				if (j == col) continue;
				minor[subi][subj] = matrix[i][j];
				subj++;
			}
			subi++;
		}
		det += sign * matrix[0][col] * determinant(minor, n - 1);
		sign = -sign;
	}

	for (int i = 0; i < n; i++)
		free(minor[i]);
	free(minor);

	return det;
}

int task1() {
	int n;
	printf("Enter the size of matrix (n x n): ");
	scanf("%d", &n);

	int **matrix = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
		matrix[i] = (int *)calloc(n, sizeof(int));

	printf("Enter the elements of matrix:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &matrix[i][j]);

	printf("Determinant of the matrix is: %d\n", determinant(matrix, n));

	for (int i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);

	return 0;
}

