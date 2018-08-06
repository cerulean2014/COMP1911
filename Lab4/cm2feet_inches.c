#include <stdio.h>
int main (void){
	int height, feet, inch;
	printf("Enter your height in centimetres: ");
	scanf("%d", &height);
	feet = height / 30.48;
	printf("Your height is %d feet ", feet);
	inch = (height - 30.48 * feet) / 2.54;
	printf("%d inches\n", inch);
	return 0;
}

