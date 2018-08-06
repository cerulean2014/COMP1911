#include <stdio.h>
int main (void){
	int i, n, nFactors;
	n = 1;
	while (n < 100){
	printf("Enter n:");
	scanf("%d", &n);
	i = 1;
	nFactors = 0;
	while (i <= n){
		if (n % i == 0){
			nFactors = nFactors + 1;
			i = i + 1;
		}
	}
	if (nFactors > 2) {
		printf("%d is composite\n", n);
	} else {
		printf("%d is prime\n", n);
	}
	return 0;
}
