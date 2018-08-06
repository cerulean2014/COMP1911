#include <stdio.h>
#include <ctype.h>

#define max 40

int main(void) {
	printf ("Enter a string: ");
	char ch[max];
	fgets(ch, max, stdin);	
	int i, number, a;
	i = 0;
	a = 0;
	while (ch[i] != '\n') {
		if (tolower(ch[i]) >= 'a' && tolower(ch[i]) <= 'z') {
			a = a + 1;
		}
		i = i + 1;
	}

// i is a counter above.

	number = i;
	int j, k;
	j = 0;
	k = 0;
	while (i >= 0 && j <= number) {
		if (tolower(ch[i]) > 'z' || tolower(ch[i]) < 'a') {
			i = i - 1;
		}
		if (tolower(ch[j]) > 'z' || tolower(ch[j]) < 'a') {
			j = j + 1;
		}
		if ((tolower(ch[i]) == tolower(ch[j])) && (tolower(ch[i]) <= 'z' && tolower(ch[i]) >= 'a') && (tolower(ch[j]) <= 'z' && tolower(ch[j]) >= 'a')) {
			k = k + 1;
			i = i - 1;
			j = j + 1;
		} else if ((tolower(ch[i]) != tolower(ch[j])) && (tolower(ch[i]) <= 'z' && tolower(ch[i]) >= 'a') && (tolower(ch[j]) <= 'z' && tolower(ch[j]) >= 'a')) {
			break;
		}
	}
//printf("k = %d", k);
//printf("a = %d", a);
	if (k == a) {
		printf("String is a palindrome\n");
	} else {
		printf("String is not a palindrome\n");
	}
	return 0;
}
