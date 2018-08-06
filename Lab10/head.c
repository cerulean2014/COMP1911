#include <stdio.h>
#include <stdlib.h>

#define max 1024

int main(int argc, char *argv[]) {
	char line[max];
	FILE *output = NULL;
	int i = 0;
	int counter;
	if (argc > 2) {
		counter = atoi(argv[2]);
		output = fopen(argv[argc - 1], "r");
		while (fgets(line, max - 1, output) != NULL && i < counter) {
			printf("%s", line);
			i++;
		}
		fclose(output);
	} else if (argc == 2) {
		output = fopen(argv[argc - 1], "r");
		counter = 10;
		while (fgets(line, max - 1, output) != NULL && i < 10) {
			printf("%s", line);
			i++;
		}
		fclose(output);
	} else {
		fprintf(stderr, "error: null pointer\n"); 
	}

	return 0;
}
