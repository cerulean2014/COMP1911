#include <stdio.h>
#include <string.h>
#define max 30

int main(void) {
	printf ("Enter a string: ");
	char ch[max];
	fgets(ch, max, stdin);	
	int i, number;
	
	i=strlen(ch);
	if (ch[i-1] == '\n') {
		i = i - 1;
	}

// i is a counter above.

	number = i;
	i = 0;
	int j;
	j = 0;
	while (i < number) {
		if (ch[i] == ch[number - 1 - i]) {
			j = j + 1;
		}
		i = i + 1;
	}

	if (j == number) {
		printf("String is a palindrome\n");
	} else {
		printf("String is not a palindrome\n");
	}
	return 0;
}
