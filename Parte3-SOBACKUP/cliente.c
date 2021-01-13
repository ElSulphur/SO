#include "Consulta.h"

typedef struct {
	int type;
	struct {
		int tipo;
        char descricao[100];
        int pid_consulta;
        int status;
	} Consulta;
} Mensagem;

//#include <stdlib.h>
//#include <signal.h>
//#include <unistd.h> para a função alarm()

int status;
int id;
Mensagem n;
//Consulta nova_consulta() {
void nova_consulta() {
    Mensagem m;
    printf("Tipos de consulta:\n");
    printf("1-Normal, 2-COVID19, 3-Urgente\n");
    printf("Qual é o tipo de consulta?\n");
	scanf("%d", &m.Consulta.tipo);
	printf("Qual é a descrição da consulta?\n");
	scanf("%s", m.Consulta.descricao);
    m.Consulta.pid_consulta=getpid();
    //printf ("%d\n", n.pid_consulta);
    id = msgget(IPC_KEY, 0);
    exit_on_error(id, "Erro no msgget");
    printf("Estou a usar a fila de mensagens id=%d\n", id);
    m.type = 1;
    status = msgsnd(id, &m, sizeof(Mensagem) - sizeof(long), 0);
    exit_on_error(status, "Erro ao enviar");



}

void trata_mensagem () {
    switch (n.Consulta.status) {
        case '2':
            printf("Consulta iniciada para o processo %d\n", getpid());
            break;
        case '3':
            printf("Consulta concluída para o processo %d\n", getpid());
            exit(0);
            break;
        case '4':
            printf("Consulta não é possível para o processo %d\n", getpid());
            exit(0);
            break;
    }
}


void trata_sinal (int sinal) {
    //SIGINT é 2
    if (sinal == SIGINT) {
        printf("Paciente cancelou o pedido");    
    
    }
}

int main () {
    nova_consulta();
    while (1){
        n.Consulta.status = -1;
        status = msgrcv(id, &n, sizeof(Mensagem) - sizeof(int), getpid(), 0);
        exit_on_error(status, "Erro ao receber");
        trata_mensagem();
        signal (SIGINT, trata_sinal);
    }
}
