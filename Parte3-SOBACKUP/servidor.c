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

int id;
int c1, c2, c3, cp;

Mensagem n;

Mensagem lista_consultas[10];

void trata_mensagem () {
    if (n.Consulta.status = 1;) {
        int i = c1 + c2 + c3;
        if (i < 10) {
            int status;
            int pid_filho = fork();
            if (pid_filho == 0) {
                lista_consultas[i] = n;
                printf ("Consulta agendada para a sala %d\n", i);
                //enviar mensagem do type 2
                sleep(10);
                printf ("Consulta terminada para a sala %d\n", i);
                //enviar mensagem do type 3
            }
            waitpid(pid_filho, &status, 0);
        } else {
            printf ("Lista de Consultas cheia!\n");
            //mandar mensagem com type 4
            Mensagem t;
            t.type = 4;
            cp++;
        }
    }
}


void trata_sinal (int sinal) {
    //SIGINT é 2
    if (sinal == SIGINT) {
        printf("Paciente cancelou o pedido");    
    }
}

void iniciar_memoria () {
    //falta ver se já existe ou não
    id = shmget (92608, 10 * sizeof(Mensagem), IPC_CREAT | 0666);
    Mensagem a;
    a.Consulta.tipo = -1;
    for (int i = 0; i < 10; i++) {
        lista_consultas[10] = a;
    }
    printf ("SHM iniciada!\n");
    //&lista_consultas
    lista_consultas = (Mensagem *) shmat (id, 0, 0);
}

int main () {
    //id = shmget (9260, 10 * sizeof(Aluno), IPC_CREAT | 0666);
    while (1) {
        
    }
    signal (SIGINT, trata_sinal);
}