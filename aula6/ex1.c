#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]){
	int i;
	for (i=0; i<argc; i++){
		printf("%d-> %s\n", i, argv[i]);
		printf("o tamanho do argumento da posição %d é %d\n", i, strlen(argv[i]));
	}
		printf("o numero de argumentos recebidos é %d\n", argc);
}
