#include <stdio.h>
int main (void){
    int x;
	printf("Please enter an integer:\n");
	scanf("%d",&x);
	printf("you entered:\n");
	if (x>5){
	    printf("a number greater than five\n");
	}else if (x==1){
	    printf("one\n");
	}else if (x==2){
	    printf("two\n");
	}else if (x==3){
	    printf("three\n");
	}else if (x==4){
	    printf("four\n");
	}else if (x==5){
	    printf("five\n");
	}else if (x<1){
	    printf("a number less than one\n");
	}
    return 0;
}
