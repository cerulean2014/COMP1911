#include <stdio.h>
int main (void){

	int i, n, j[10], k[10], s, m, l[10];
	i = 0;
	n = 0;
	s = 0;
	m = 0;
	// this part is to scan 20 numbers for 2 vectors.
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

	// this part is to distinguish match
	i = 0;
	n = 0;
	while(i < 10 && n < 10){
		if(j[i] == k[n]){
			s++;
		}
		n++;
		i++;
	}

	//this part is aim to delete match part.

	i = 0;
	n = 0;
	while(i < 10 && n < 10){
		if(j[i] == k[n]){
			j[i] = 0;
			k[n] = 0;
		}
		i++;
		n++;
	}

	//this part is to find left mismatch part.
	
	i = 0;
	n = 0;

	//when both j[i] and k[n] are not 0, if they are the same, we get 1 mismatch, and then set these two numbers to 0, then start it again.

	while(i < 10){
		if (j[i] != 0){
			while(n < 10){
				if (k[n] != 0){
					if (j[i] == k[n]){
						m++;
						j[i] = 0;
						k[n] = 0;
						break;
	//after being break, we add 1 to i.
					}
				}

	//when we can not find a k[n] which equals to j[i], we continue to roll until we find one or n = 10

			n++;
			}
	//then we need to roll i, so set n to be 0
			n = 0;
		}
	//and start to roll i now.
		i++;
	}

	printf("Vectors match in %d positions.\n", s);
	printf("Vectors mismatch in %d positions.\n", m);

	return 0;
}
