#include "defines.h"
typedef struct {
	long tipo;
	struct {
		char texto[80];
		char nome[20];
		int pid;
	} conteudo;
} mensagem;

int main () {
	int id, status;
	id = msgget(IPC_KEY, 0666 | IPC_CREAT);
	exit_on_error(id, "Erro no msgget.");
	printf("estou a usar a fila de mensagens id=%d\n", id);
	
	mensagem m;
	while (1) {
		status=msgrcv(id, &m, sizeof(m.conteudo), 1, 0);
		exit_on_error(status, "erro ao receber");
		printf("Recebi de %s a msg: %s\n", m.conteudo.nome, m.conteudo.texto);
		
		m.tipo = m.conteudo.pid;
		sprintf(m.conteudo.texto, "Sr(a) %s recebi a sua msg\n", m.conteudo.nome);
		status = msgsnd(id, &m, sizeof(m.conteudo), 0);
		exit_on_error(status, "erro ao enviar");
	}
}
