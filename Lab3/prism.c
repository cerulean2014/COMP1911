#include <stdio.h>
int main (void) {
int l,w,h,Volume,Area,Edge_length;
	printf("Please enter prism length: ");
	scanf("%d",&l);
	printf("Please enter prism width: ");
	scanf("%d",&w);
	printf("Please enter prism height: ");
	scanf("%d",&h);
	Volume=l*w*h;
	Area=2*l*w+2*w*h+2*h*l;
	Edge_length=4*l+4*w+4*h;
	printf("A prism with sides");
	printf(" %d %d %d",l,w,h);
	printf(" has:\n");
	printf("Volume      = %d\n",Volume);
	printf("Area        = %d\n",Area);
	printf("Edge length = %d\n",Edge_length);
	return 0;
}

