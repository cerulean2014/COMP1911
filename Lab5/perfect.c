#include <stdio.h>
int main (void){
	int number, factor, sum;
	number = 0;
	factor = 1;
	sum = 0;

	printf("Enter number: ");
	scanf("%d", &number);

	printf("The factors of %d are:\n", number);

	while (factor <= number){
		if ( 0 == number % factor ) {
			printf("%d\n", factor);	
			sum = sum + factor;
		}
		factor = factor + 1;
	}

	printf("Sum of factors = %d\n", sum);
	if ( sum == 2 * number){
		printf("%d is a perfect number\n", number);
	} else {
		printf("%d is not a perfect number\n", number);
	}
	return 0;
}
