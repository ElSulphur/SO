#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
int i;
printf ("mostrar o conteudo da diretoria:\n");

i=fork();

if (i == 0)
{
	execl("/bin/ls", "ls", "-l", "/", NULL);
}
else
{
	printf("eu sou o pai \n");
}

printf ("Fim do comando");



}
