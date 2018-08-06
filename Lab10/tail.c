#include<stdio.h>

int main(int argc, char *argv[]){
	char line[1024];
	if (argc == 2) {
		FILE *output;
		output = fopen(argv[argc - 1], "r");
		int many = 0;
		while (fgets (line, 1023 , output) != NULL) {
			many++;
		}
		fclose(output);

		int begin = 0;
		if (many >= 10) {
			begin = many - 9;
		}
//printf("begin = %d", begin);
		int i = 0;
		FILE *f;
		f = fopen (argv[argc - 1], "r");
		while (fgets (line, 1023, f) != NULL) {
			i++;
			if (i >= begin) {
				printf("%s", line);
			}
		}
		fclose(f);
	} else {
		fprintf(stderr, "error: null pointer\n"); 
	}
	return 0;
}

