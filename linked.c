#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process {
		char name[10];
		int size;
		int *alloc_blocks; // Using a pointer to allocate memory dynamically
		int flag; // 0 - free, 1 - not enough memory, 2 - allocated
};

int random_num(int size, int exclude[], int exclude_count) {
		int random, i;
		int is_excluded = 1;

		while (is_excluded) {
				is_excluded = 0;
				random = rand() % size;
				for (i = 0; i < exclude_count; i++) {
						if (random == exclude[i]) {
								is_excluded = 1;
								break;
						}
				}
		}
		return random;
}

void recurse(int file[], struct Process p[], int size, int num_pro) {
		int exclude_count = 0;
		int *exclude = malloc(size * sizeof(int)); // Dynamically allocated memory for exclude array
		int i, j, size_left = 0;

		for (i = 0; i < num_pro; i++) {
				printf("Enter the name of the process %d: ", i + 1);
				scanf("%s", p[i].name);
				printf("Enter the size of the process %d: ", i + 1);
				scanf("%d", &p[i].size);

				p[i].alloc_blocks = malloc(p[i].size * sizeof(int)); // Dynamically allocate memory for alloc_blocks

				if (size_left + p[i].size > size) {
						printf("Memory Blocks not enough for Process Allocation\n");
						p[i].flag = 1;
				} else {
						size_left += p[i].size;
						for (j = 0; j < p[i].size; j++) {
								int rand = random_num(size, exclude, exclude_count);
								p[i].alloc_blocks[j] = rand;
								exclude[exclude_count] = rand;
								exclude_count++;
						}
						p[i].flag = 2;  // Allocation Successful
				}
		}
		free(exclude); // Free dynamically allocated memory
}

void display(struct Process p[], int num_pro) {
		printf("\nFile Allocation Table\n\n");
		printf("Name\t\tSize\t\tAllocated Blocks\n");

		for (int i = 0; i < num_pro; i++) {
				printf("%s\t\t%d\t\t", p[i].name, p[i].size);

				if (p[i].flag == 1) {
						printf("Not Enough Memory to be Allocated\n");
				} else {
						for (int j = 0; j < p[i].size; j++) {
								printf("%d ", p[i].alloc_blocks[j]);
						}
						printf("\n");
				}
		}
}

int main() {
		//srand(time(NULL));

		int size;
		printf("Enter the Number of Blocks: ");
		scanf("%d", &size);

		int file[size];

		for (int i = 0; i < size; i++) {
				file[i] = 0;
		}

		int num_pro;
		printf("Enter the Number of Processes: ");
		scanf("%d", &num_pro);

		struct Process p[num_pro];

		for (int i = 0; i < num_pro; i++) {
				p[i].flag = 0;
		}

		recurse(file, p, size, num_pro);
		display(p, num_pro);

		return 0;
}
