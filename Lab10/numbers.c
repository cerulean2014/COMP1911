#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *output;
	output = fopen(argv[argc - 1], "w");
	int i = atoi(argv[1]);
	int j = atoi(argv[2]);
	while (i <= j) {
		fprintf(output, "%d\n", i);
		i++;
	}
	fclose (output);
	return 0;
}
