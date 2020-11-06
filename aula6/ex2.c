#include <stdio.h>
#include <stdlib.h>

	void swap (int* x, int *y){
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}

	int main (int argc, char *argv[]){
		int x;
		int y;
		x=atoi(argv[1]);
		y=atoi(argv[2]);
	//	printf (" %d %d\n", x, y);
		printf ("Vaemos trocar o x com o y\n");
		swap(&x,&y);
		printf ("%d %d\n", x, y);
	}
