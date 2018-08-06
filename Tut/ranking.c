#include <stdio.h>

int main(){
	int dice[5];
	int i, j, a, sum, twosame, t;

	for(i = 0; i < 5; i++)
		scanf("%d", &dice[i]);

	for(i = 0; i < 5; i++){
		for(j = i + 1; j < 5; j++){
			if(dice[i] > dice[j]){
				a = dice[i];
				dice[i] = dice[j];
				dice[j] = a;
			}
		}
	}

	for(i = 0; i < 5; i++)
		printf("%d", dice[i]);

	printf("\n");
	return 0;
}
