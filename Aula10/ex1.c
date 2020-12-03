#include "defines.h"
typedef struct {
	int num;
	char nome[100];
	float nota;
} Aluno;

int main () {
	int id = shmget (9260, 20 * sizeof(Aluno), IPC_CREAT | 0666);
	exit_on_error(id, "shmget");
	
	printf("%d\n", id);

	Aluno* a = (Aluno *)shmat(id, 0, 0);
//	printf("%d\n",id2);
//	if (a == NULL) { perror("erro no attach"); exit (1);}
int i;
for (i=0; i<20;i++) {
	a[i].num=-1;
	strcpy(a[i].nome,"sem nada");
	a[i].nota=0.0;
}

int b;
for (b=0; b < 20; b++){
	printf("Pos %d; %d %s %f\n", i, a[i].num, a[i].nome, a[i].nota);
}
}
