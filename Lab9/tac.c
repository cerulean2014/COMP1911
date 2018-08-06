#include <stdio.h>

#define max_char 128
#define max_line 1024

int main(void) {

	int i, j, set[max_line][max_char];	
	i = 0;
	j = 0;
	int c[max_char] = {};

	set[i][c[i]] = getchar();
	while (set[i][c[i]] != EOF) {
		while (set[i][c[i]] != '\n') {
			c[i]++;
			set[i][c[i]] = getchar();
		}
		c[i]--;
		i++;
		set[i][c[i]] = getchar();
	}
	i--;

	while (i >= 0) {
		while (j <= c[i]) {
			printf("%c", set[i][j]);
			j++;
		}
		printf("\n");
		i--;
		j = 0;
	}

	return 0;
}
