#include "defines.h"
typedef struct {
	int num;
	char nome[100];
	float nota;
} Aluno;

int main () {
	int id=shmget(9230, 20 * sizeof(Aluno), IPC_CREAT | 0666);
	exit_on_error(id, "shmget");

	Aluno* a=(Aluno *)shmat(id, 0, 0);
	printf("%d\n", id2);
}
