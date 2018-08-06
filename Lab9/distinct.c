#include <stdio.h>
#include <stdlib.h>

#define max_char 128
#define max_line 1024

int main(int argc, char *argv[]) {
	int i, distinct = 0;
	char set[max_line][max_char];
	i = 0;
	distinct = atoi(argv[1]);

	while (fgets(set[i], max_char, stdin) != NULL) {
		i = i + 1;
	}

	int k = 1;
	// is it because the program also fgets the part ./distinct ?
	// we can not use k = 0, otherwise e will be counted one more.
	int a = 0;
	int different = 0;
	// 0 means same, 1 means different.
	int b = 1;
	int c = 0;
	int e = 0;
	// two counters to compare.
	while (k < i && b < distinct) {
		a = k - 1;
		while (a >= 0) {
			while (c < max_char) {
				if (set[k][c] != set[a][c]) {
					different = 1;
					// if and only if there exists something different, that should be counted.
				}
				c = c + 1;
			}
			a = a - 1;
			c = 0;
			if (different == 1) {
				e = e + 1;
			}
			different = 0;
		}
		if (e == k) {
			// e == k means that the set[k] are different from all the former set that we have had, so counter b can be added by 1.
			b = b + 1;
		}
		e = 0;
		k = k + 1;
	}
		

	printf("%d distinct lines seen after %d lines read.\n", b, k);
	
	return 0;
}
