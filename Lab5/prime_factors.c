#include <stdio.h>
int main (void){
	int number, factor, test, enter, factory, factorio;
	number = 0;
	factor = 2;
	test = 2;
	enter = 0;
	factory = 2;
	factorio = 0;

	printf("Enter number: ");
	scanf("%d", &number);

	enter = number;
	if ( number < 2){
		printf("Undefined value\n");
	}else{
		while ( factor < number){
			if ( number % factor != 0){
				factor = factor + 1;
			}else{
				printf("The prime factorization of %d is:\n", enter);
				printf("%d", factor);
				factorio = factor;
				factor = number + 1;
			}
		}
		if(factor == number){
			printf("%d is prime\n", number);
		}else{
			number = number / factorio;
			while(factory <= number){
				if (number % factory != 0){
					factory = factory + 1;
				}else{
					printf(" * %d", factory);
					number = number / factory;
				}
			}
			printf(" = %d\n", enter);
		}
	}
	return 0;
}
