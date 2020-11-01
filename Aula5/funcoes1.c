#include <stdio.h>

int primoQ (int N) {

for (int i=2; i<N/2; i++){
	if (N % i == 0) return 0;
}	
return 1;
}

int minimo(int *v, int comp){
a=0;
for (int i=1; i<comp;i++){
	if (v[i] < a){
		a=v[i];
	}
}
}

int main (){
int resultado1;
int numero1;
printf("diga um numero:\n");
scanf("%d", &numero1);
resultado1=primoQ(numero1);
printf("%d\n", resultado1);
if ( resultado1==0)
{ printf("o numero nao é primo\n");}
else {
printf ("o numero é primo\n");
}

int vector[3]={1,2,3}
int resultado2;
resultado2=minimo(vector, 3);
printf("%d\n", resultado2);


}
