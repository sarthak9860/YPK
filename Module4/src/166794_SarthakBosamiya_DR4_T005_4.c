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
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#define SECTOR_SIZE 512  // Boot sector size in bytes

struct BootSector {
	uint8_t jump[3];          // Jump instruction
	char systemID[8];         // System ID
	uint16_t bytesPerSector;  // Bytes per sector
	uint8_t sectorsPerCluster;
	uint16_t reservedSectors;
	uint8_t fatCopies;
	uint16_t rootDirEntries;
	uint16_t totalSectors;
	uint8_t mediaDescriptor;
	uint16_t sectorsPerFAT;
	uint16_t sectorsPerTrack;
	uint16_t numberOfSides;
	uint16_t hiddenSectors;
} __attribute__((packed));  // Prevent struct padding

int task4() {
	struct BootSector boot;
	int fd = open("/dev/sda", O_RDONLY); // Change to "/dev/fd0" for floppy

	if (fd < 0) {
		perror("Error opening disk");
		return 1;
	}

	if (read(fd, &boot, SECTOR_SIZE) != SECTOR_SIZE) {
		perror("Error reading boot sector");
		close(fd);
		return 1;
	}

	close(fd);

	printf("\n--- Boot Sector Information ---\n");
	printf("System ID: %.8s\n", boot.systemID);
	printf("Bytes per Sector: %u\n", boot.bytesPerSector);
	printf("Sectors per Cluster: %u\n", boot.sectorsPerCluster);
	printf("Reserved Sectors: %u\n", boot.reservedSectors);
	printf("Number of FAT Copies: %u\n", boot.fatCopies);
	printf("Root Directory Entries: %u\n", boot.rootDirEntries);
	printf("Total Sectors: %u\n", boot.totalSectors);
	printf("Media Descriptor: 0x%X\n", boot.mediaDescriptor);
	printf("Sectors per FAT: %u\n", boot.sectorsPerFAT);
	printf("Sectors per Track: %u\n", boot.sectorsPerTrack);
	printf("Number of Sides: %u\n", boot.numberOfSides);
	printf("Hidden Sectors: %u\n", boot.hiddenSectors);

	return 0;
}


