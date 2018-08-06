#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *output;
	output = fopen("1000.txt", "w");
	int i = 1;
	while (i <= 1000) {
		fprintf(output, "%d\n", i);
		i++;
	}
	fclose (output);
	return 0;
}
