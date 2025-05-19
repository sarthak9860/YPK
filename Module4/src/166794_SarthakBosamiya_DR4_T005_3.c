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
#include <string.h>
#include <dirent.h>

struct Node {
	char filename[256];  // Maximum filename length
	struct Node* next;
};

void insert_sorted(struct Node** head, char* filename) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(new_node->filename, filename);
	new_node->next = NULL;

	if (*head == NULL || strcmp((*head)->filename, filename) > 0) {
		new_node->next = *head;
		*head = new_node;
		return;
	}

	struct Node* current = *head;
	while (current->next != NULL && strcmp(current->next->filename, filename) < 0) {
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;
}

void display_list(struct Node* head) {
	struct Node* current = head;
	printf("\nFiles in directory (sorted):\n");
	while (current != NULL) {
		printf("%s\n", current->filename);
		current = current->next;
	}
}

void free_list(struct Node* head) {
	struct Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int task3() {
	DIR* dir;
	struct dirent* entry;
	struct Node* head = NULL;
	char dirname[256];

	printf("Enter directory path: ");
	scanf("%s", dirname);

	dir = opendir(dirname);
	if (dir == NULL) {
		perror("Error opening directory");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_REG || entry->d_type == DT_DIR) { // Regular files and directories
			insert_sorted(&head, entry->d_name);
		}
	}

	closedir(dir);
	display_list(head);
	free_list(head);

	return 0;
}


