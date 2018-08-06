#include <stdio.h>

#define max 40

int main(void) {
	printf("Enter a string: ");

	char ch[max];
	fgets(ch, max, stdin);

	int i;
	i = 0;

	while (ch[i] != '\n') {
		if (ch[i] != ' ') {
			putchar(ch[i]);
		}
		putchar('\n');
		i = i + 1;
	}

	return 0;
}
	
