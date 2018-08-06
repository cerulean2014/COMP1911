#include <stdio.h>
int main (void){

	int i, max, min, z[10], result,total;
	double average;
	//should total be double?
	i = 0;
	max = 0;
	min = 0;
	total = 0.0;
	result = 0;
	printf("Enter vector of 10 numbers: ");

	while ( i < 10){
		result = scanf("%d", &z[i]);
		if (result == 1){

			if (i == 0){
				max = z[0];
				min = z[0];
			}
			// assign values to max and min.

			if (z[i] > max){
				max = z[i];
			}
			if (z[i] < min){
				min = z[i];
			}
			// change values for max and min.
			
			total = total + z[i];

		}else{
			printf("Sorry I couldn't read enough numbers\n");
			return 0;
		}
		i++;
	}
	
	average = (double)total / 10;
	printf("Minimum vector value is %d\n", min);
	printf("Maximum vector value is %d\n", max);
	printf("Average vector value is %.1lf\n", average);
	return 0;
}
