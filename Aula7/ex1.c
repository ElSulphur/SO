#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
int i;
printf ("Inicio PID=%d filho de %d\n", getpid(), getppid());

i=fork();

if (i == 0)
{
	printf("eu sou o filho \n");  
}
else
{
	printf("eu sou o pai \n");  
}

wait(NULL);

printf ("Fim de PID=%d filho de %d\n", getpid(), getppid());



}
