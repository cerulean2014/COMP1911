#include <stdio.h>
#define size 3
int main(void) {
	int i, j, z[size][size], win, k;
	i = 0;
	j = 0;
	win = 0;
	printf ("Please enter the board:\n");
	while (i < size) {
		j = 0;
		while (j < size) {
			scanf("%d", &z[i][j]);
			j = j + 1;
		}
		i = i + 1;
	}
	i = 0;
	j = 0;

	printf ("Here is the board:\n\n");
	while (i < size) {
		j = 0;
		while (j < size - 1) {
			if (z[i][j] == 0) {
				printf ("O ");
			} else if (z[i][j] == 1) {
				printf ("X ");
			} else if (z[i][j] == 2) {
				printf (". ");
			}
			j = j + 1;
		}
		if (j == size - 1) {
			if (z[i][j] == 0) {
				printf ("O");
			} else if (z[i][j] == 1) {
				printf ("X");
			}else if (z[i][j] == 2) {
				printf (".");
			}
		}
		printf ("\n");
		i = i + 1;
	}
//the part above for exercise 1
	i = 0;
	j = 1;
	while (i < size) {
		while (j < size) {
			if (z[i][0] == z[i][j]) {
				win = win + 1;
			}
			j = j + 1;
		}
		if (win == size - 1) {
			if (z[i][0] == 0) {
				printf ("\nNoughts win\n");
				return 0;
			} else if (z[i][0] == 1){
				printf ("\nCrosses win\n");
				return 0;
			}
		}
		j = 1;
		win = 0;
		i = i + 1;
	}
	

	i = 1;
	j = 0;
	win = 0;
	while (j < size) {
		while (i < size) {
			if (z[0][j] == z[i][j]) {
				win = win + 1;
			}
			i = i + 1;
		}
		if (win == size - 1) {
			if (z[0][j] == 0) {
				printf ("\nNoughts win\n");
				return 0;
			} else if (z[0][j] == 1){
				printf ("\nCrosses win\n");
				return 0;
			}
		}
		i = 1;
		win = 0;
		j = j + 1;
	}
	








//the part above is for exercise 2
	i = 0;
	j = 0;
	while (i < size) {
		if (z[i][i] == z[0][0]) {
			j = j + 1;
		}
		i = i + 1;
	}
	if (j == size) {
		if (z[0][0] == 0) {
			printf ("\nNoughts win\n");
			return 0;
		} else if (z[0][0] == 1) {
			printf ("\nCrosses win\n");
			return 0;
		} 
	}

	i = size - 1;
	j = 0;
	k = 0;
	while (k < size) {
//left way diagonal
		if (z[k][i] == z[k + 1][i - 1]) {
			j = j + 1;
		}
		k = k + 1;
		i = i - 1;
	}
	if (j == size - 1) {
		if (z[0][j] == 0) {
			printf ("\nNoughts win\n");
			return 0;
		} else if (z[0][j] == 1) {
			printf ("\nCrosses win\n");
			return 0;
		} else {
			printf ("\nThere are no winners\n");
		}
	}

	return 0;
}
