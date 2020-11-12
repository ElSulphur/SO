#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


void handler (int sinal) {

printf("recebi um sinal!!\n");

}


int main () {

	char s[100];
	printf("PID=%d\n", getpid());

	signal(SIGUSR1, handler);

	while (1) {
		printf("Comando: \n");
		fgets(s, 100, stdin);
		s[strlen(s)-1]='\0';
		if (strcmp(s, "sair") == 0)
			exit(0);
	}
}
