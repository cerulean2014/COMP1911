#include <stdio.h>
int main (void){

	int i, n, j[10], k[10], s;
	i = 0;
	n = 0;
	s = 0;

	printf("Enter vector 1 of 10 positive numbers: ");
	while(i < 10){
		scanf("%d", &j[i]);
		i++;
	}

	printf("Enter vector 2 of 10 positive numbers: ");
	while(n < 10){
		scanf("%d", &k[n]);
		n++;
	}

	i = 0;
	n = 0;
	while(i < 10 && n < 10){
		if(j[i] == k[n]){
			s++;
		}
		i++;
		n++;
	}

	printf("Vectors match in %d positions.\n", s);

	return 0;
}
