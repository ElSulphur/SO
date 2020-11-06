#include "pauta.h"
#define tpauta 10

Aluno novo_aluno() {
	Aluno n;
	printf("Numero do aluno:\n");
	scanf("%d", &n.num);
	printf("Nome do aluno:\n");
	scanf("%s", n.nome);
	printf("Nota do aluno:\n");
	scanf("%f", &n.nota);
	return n;

}

void mostra_pauta(Aluno *pauta, int tam){
	int i;
	for (i=0; i<tam; i++) {
		printf("%d %s %f\n", pauta[i].num, pauta[i].nome, pauta[i].nota);
	}
	printf("o total de alunos na turma é: %d\n", i);
}


int main(){
	Aluno a;
	a.num = 23500;
	strcpy(a.nome, "Manuel Francisco");
	a.nota = 19.5;
	printf ("Aluno: %d, %s, %.2f\n", a.num, a.nome, a.nota);
	Aluno pauta[10];
	for (int i=0; i<10; i++){
		pauta[i].num=-1;
	//	pauta[0]=a;
	}
	pauta[0]=a;
	//mostra_pauta(pauta, tpauta);
	//Aluno new;
	//new=novo_aluno();
	
	Aluno al;
	al=novo_aluno();
	FILE *fb=fopen("pauta.dat", "a");
	fwrite(%a1, sizeof(a), 1, fb);
	fclose(fb);

}
