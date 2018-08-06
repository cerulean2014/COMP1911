#include <stdio.h>
int main (void){
	int x,low,up;
	printf("Enter your age: ");
	scanf("%d",&x);
	low=(x/2)+7;
	up=(x-7)*2;
	if (x<15){
		printf("You are too young to be dating.\n");
	} 
	else if(x>=15){
		printf("Your dating range is %d to %d years old.\n",low,up);
	}
	return 0;
}
