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

#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void display_attributes(const char *filename) {
	struct stat fileStat;
	if (stat(filename, &fileStat) < 0) {
		perror("Error reading file attributes");
		return;
	}

	printf("File: %s\n", filename);
	printf("Read-Only: %s\n", (fileStat.st_mode & S_IWUSR) ? "No" : "Yes");
	printf("Hidden: %s\n", (filename[0] == '.') ? "Yes" : "No");
	printf("System File: %s\n", (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");
}

void modify_attributes(const char *filename, int make_readonly) {
	struct stat fileStat;
	if (stat(filename, &fileStat) < 0) {
		perror("Error reading file attributes");
		return;
	}

	mode_t newMode = fileStat.st_mode;
	if (make_readonly)
		newMode &= ~(S_IWUSR);  // Remove write permission
	else
		newMode |= S_IWUSR;  // Add write permission

	if (chmod(filename, newMode) < 0)
		perror("Error changing attributes");
	else
		printf("File attributes updated successfully.\n");
}

int task2() {
	char filename[256];
	int choice;

	printf("Enter filename: ");
	scanf("%255s", filename);
	display_attributes(filename);

	printf("Do you want to make it read-only? (1-Yes, 0-No): ");
	scanf("%d", &choice);

	modify_attributes(filename, choice);
	return 0;
}

