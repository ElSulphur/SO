#include <stdio.h>
int main() {
	int a, b;
	printf("Diga dois numeros: ");
	scanf ("%d", &a);
	scanf ("%d", &b);
	printf ("%d + %d = %d \n", a, b, a+b);
	if (a>b)
	{printf("o maior é %d\n",a);}
	else
	{printf("o maior é %d\n",b);}

	if (a>b)
	{printf("%d %d \n",b , a);}
	else
	{printf("%d %d \n", a, b);}

}
