#include <stdio.h>
int main (void){
	int a, b, c;
	a=0;
	b=0;
	c=0;
	printf("Please enter three integers:\n");
	scanf("%d %d %d", &a, &b, &c);
	printf("Your integers after sorting: ");
	printf("\n");
	if (a >= b && a >= c){
		if (b > c){
			printf("%d %d %d", a, b, c);
		}else{
			printf("%d %d %d", a, c, b);
		}
	}
	if ( b > a && b >= c){
		if (a > c){
			printf("%d %d %d", b, a, c);
		}else{
			printf("%d %d %d", b, c, a);
		}
	}
	if (c > a && c > b){
		if (a > b){
			printf("%d %d %d", c, a, b);
		}else{
			printf("%d %d %d", c, b, a);
		}
	}
	printf("\n");
	return 0;
}

