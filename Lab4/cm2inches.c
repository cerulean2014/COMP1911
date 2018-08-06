#include <stdio.h>
int main (void){
	int ct;
	int ic;
	ct = 0;
	ic = 0;
	printf("Enter your height in centimetres: ");
	scanf("%d", &ct);
	ic = ct / 2.54;
	printf("Your height in inches is ");
	printf("%d", ic);
	printf("\n");
	return 0;
}

