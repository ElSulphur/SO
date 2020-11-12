#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int n=0;

void trata_sinal (int sinal) {
	printf("Recebi sinal %d\n", sinal);
	n = 1;
}

//esta funcao termina alinea 3. c)
void trata_sinal2 (int sinal) {
	printf ("Vai terminar...\n");
	exit (-1);
}

int main () {
	printf ("esperar 5 segundos...\n");
	signal ( SIGALRM, trata_sinal );
	signal ( SIGINT, trata_sinal2 );
	alarm (5);
	pause();
	while (n == 0 ) ;
	printf ("ok\n");
	return 0;
}
