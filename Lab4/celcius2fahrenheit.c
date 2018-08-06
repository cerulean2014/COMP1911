#include <stdio.h>
int main (void){
	double celcius, fahrenheit;
	celcius = 0;
	fahrenheit = 0;
	printf("Please enter fahrenheit:");
	scanf("%lf", &fahrenheit);
	celcius = (fahrenheit - 32) * 5 / 9;
	printf("Your degree in celcius is: %0.2lf \n", celcius);
	return 0;
}
