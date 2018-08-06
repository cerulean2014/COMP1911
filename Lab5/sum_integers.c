#include <stdio.h>
int main (void){
	int i, sum;
	i = 1;
	sum = 0;
	printf(" k sum\n\n");
	while(i <= 20){
		sum = sum + i;
		printf("%2d %3d\n", i, sum);
		i = i + 1;
	}
	return 0;
}
	
