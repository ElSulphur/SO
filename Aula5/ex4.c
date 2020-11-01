#include <stdio.h>
int main (){
int v[10];
printf ("Introduza 10 algarismos\n");
for (int i=0; i < 10; i++) {
	scanf("%d", &v[i]);
//	printf("o número %d foi guardado na posição %d\n", v[i], i);
}
int a=0;
for (int i=0; i < 10; i++){
	printf("%d ", v[9-i]);
	if (v[9-i] > a){
		a=v[9-i];
	}
}
printf("O máximo é %d\n", a);
}
