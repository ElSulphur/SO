#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main () {

int n;

printf("enviar um sinal para : ");
scanf("%d", &n);

kill(n,SIGUSR1);

return 0;
}
