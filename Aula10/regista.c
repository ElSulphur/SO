#include "defines.h"
typedef struct {
	int num;
	char nome[100];
	float nota;
} Aluno;

struct smbuf DOWN = {0, -1, 0};
struct sembuf UP = {0, 1, 0};

Aluno obter_dados_aluno() {
	Aluno x;
	char s[100];
	printf("Diga Num: ");
	fgets(s, 100, stdin); x.num=atoi(s);
	printf("Diga Nome: ");
	fgets(x.nome, 100, stdin); x.nome[strlen(x.nome)-1]=0;
	printf("Diga nota: ");
	fgets(s, 100, stdin); x.nota = atof(s);
	return x;
}

void registar_aluno (Aluno *mem, Aluno x) {
	int i;
	for (i=0; i<20; i++){
		if (mem[i].num == -1) {
			printf("A colocar posicao %d\n", i);
			mem[i] = x;
			break;
		}
	}
}

int main () {
	int id = shmget (9260, 20 * sizeof(Aluno), IPC_CREAT | 0666);
	exit_on_error(id, "shmget");
	
	int sem_id=semget(9260, 5, 0);
	exit_on_error (status, "SETVAL");


	printf("%d\n", id);

	int status=semop(sem_id,"semget");
	exit_on_error(status,"DOWN");
//	Aluno* a = (Aluno *)shmat(id, 0, 0);
	Aluno x=obter_dados_aluno();
	registar_aluno(a, x);
	int status2 = semop(sem_id, &UP, 1);
	exit_on_error(status2, "UP");
//	printf("%d\n",id2);
//	if (a == NULL) { perror("erro no attach"); exit (1);}
//for (b=0; b < 20; b++){
//	printf("Pos %d; %d %s %f\n", i, a[i].num, a[i].nome, a[i].nota);
//}
}
