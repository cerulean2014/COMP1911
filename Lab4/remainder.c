#include <stdio.h>
int main (void){
	int number, divisor, remainder, result, test;
	number = 0;
	divisor = 1000000000;
	remainder = 0;
	result = 0;
	test = 0;
	printf("Enter your number: ");
	scanf("%d", &number);
	remainder = number;
	test = number;
	printf("The numbers after decomposing %d are:\n", number);
	while(divisor > test){
		divisor = divisor / 10;
	}
	while(remainder >= 0 && divisor > 0){
		result = remainder / divisor;
		remainder = remainder % divisor;
		divisor = divisor / 10;
		printf("%d ",result);
	}
	printf("\n");
	return 0;
}
