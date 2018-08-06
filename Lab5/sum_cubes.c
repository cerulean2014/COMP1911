#include <stdio.h>
int main (void){
	int i, cube, cubes;
	i = 1;
	cube = 0;
	cubes = 0;
	printf(" k cubes\n\n");
	while(i <= 20){
		cube = i * i * i;
		cubes = cubes + cube;
		printf("%2d %5d\n", i, cubes);
		i = i + 1;
	}
	return 0;
}
