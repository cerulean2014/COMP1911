#include <stdio.h>
int main (void){
	int a, b;
	a = 0;
	b = 0;
	printf("Enter start year: ");
	scanf("%d", &a);
	printf("Enter finish year: ");
	scanf("%d", &b);
	while (a <= b){
		if (a % 4 == 0){
			if (a % 100 != 0 || a % 400 == 0){
				printf("%d\n", a);
				a = a + 4;
			}else{
				printf("");
				a = a + 4;
			}
		}else{
			a = a + 1;
		}
	}
	return 0;
}
