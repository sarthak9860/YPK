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
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#define MBR_SIZE 512
#define PARTITION_TABLE_OFFSET 446
#define NUM_PARTITIONS 4
#define PARTITION_ENTRY_SIZE 16

struct PartitionEntry {
	uint8_t boot_flag;        // Boot indicator (0x80 = active, 0x00 = inactive)
	uint8_t start_chs[3];     // Start CHS address (Cylinder-Head-Sector)
	uint8_t type;             // Partition type (0 = unused, 4 = FAT16, 5 = Extended, etc.)
	uint8_t end_chs[3];       // End CHS address
	uint32_t start_lba;       // Starting LBA address
	uint32_t total_sectors;   // Total sectors in partition
};

void read_partition_table(const char *disk) {
	int fd;
	uint8_t mbr[MBR_SIZE];
	struct PartitionEntry partitions[NUM_PARTITIONS];

	fd = open(disk, O_RDONLY);
	if (fd == -1) {
		perror("Error opening disk");
		return;
	}

	if (read(fd, mbr, MBR_SIZE) != MBR_SIZE) {
		perror("Error reading MBR");
		close(fd);
		return;
	}

	close(fd);

	for (int i = 0; i < NUM_PARTITIONS; i++) {
		int offset = PARTITION_TABLE_OFFSET + (i * PARTITION_ENTRY_SIZE);
		struct PartitionEntry *p = (struct PartitionEntry *)(mbr + offset);

		partitions[i] = *p;

		printf("\nPartition %d:\n", i + 1);
		printf("  Boot Flag: 0x%02X (%s)\n", p->boot_flag, (p->boot_flag == 0x80) ? "Active" : "Inactive");
		printf("  Partition Type: 0x%02X\n", p->type);
		printf("  Start LBA: %u\n", p->start_lba);
		printf("  Total Sectors: %u\n", p->total_sectors);
		printf("  Approx. Size: %.2f GB\n", (p->total_sectors * 512.0) / (1024 * 1024 * 1024));
	}
}

int task5() {
	const char *disk_path = "/dev/sda";

	printf("Reading Partition Table from %s...\n", disk_path);
	read_partition_table(disk_path);

	return 0;
}
