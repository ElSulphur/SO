#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "consulta.h"

int c1=0;
int c2=0;
int c3=0;
//consulta perdida
int cp=0;
int p;
Consulta lista_consultas[10];

void inicio_lista() {
	for (int i=0; i < 10; i++) {
		Consulta n;
		n.tipo=-1;
		lista_consultas[i]=n;	
	}		
}

void receber_consulta (int sinal) {
    printf("Joel\n");
    //if (signal = SIGUSR1) {
    if (sinal = 10) {
        Consulta n;
        //char *linha[100];
        //FILE *ft=fopen("PedidoConsulta.txt", "r");
        //fscanf(ft, "%s\n", linha);
        //fclose(ft); 
        //n.tipo = atoi(strtok(linha, " "));
        //printf ("%s\n", n.tipo);
        FILE *ft=fopen("PedidoConsulta.txt", "r");
        fscanf(ft, "%d %s %d\n", &n.tipo, n.descricao, &n.pid_consulta);
        //fclose(ft); 
        printf("Chegou novo pedido de consulta do tipo %d, descricao %s e PID %d\n", n.tipo, n.descricao, n.pid_consulta);
        int i=c1+c2+c3;
        fclose(ft); 
        if (i < 10) {
            lista_consultas[i]=n;
				printf("Consulta agendada para a sala %d\n", &i);
				if (n.tipo == 1) {
					c1++;
				} else if (n.tipo == 2) {
					c2++;
				} else if (n.tipo == 3) {
					c3++;
				}
				int pid_filho=fork();
                int status;
                if (pid_filho == 0) {
                    printf("mambos do filho\n");
                    printf("Consulta iniciada na sala %d\n", i);
                    kill (n.pid_consulta, SIGHUP);
                    sleep(10);
                    printf("Consulta terminada na sala %d\n", i);
                    kill (n.pid_consulta, SIGTERM);	
                    exit (EXIT_SUCCESS);
                    //exit(0);
                }
                waitpid(pid_filho, &status, 0);
				//sleep(10);
                //ctrl k c
                // printf("Consulta terminada na sala %i", &i);
                // kill (n.pid_consulta, SIGTERM);	
        } else {
            printf("Lista de consultas cheias\n");
            //mandar o signal SIGUSR2 ao processo <pid_consulta>
            kill (n.pid_consulta, SIGUSR2);
            cp++;
        }
    }
    //SIGINT sinal emitido quando admin faz ctrl c
	if (sinal == SIGINT) {
		remove ("SrvConsultas.pid");
		FILE *fb=fopen("StatsConsultas.dat", "a");
		fwrite(&c1, sizeof(c1), 1, fb);
		fwrite(&c2, sizeof(c2), 1, fb);
		fwrite(&c3, sizeof(c3), 1, fb);
		fwrite(&cp, sizeof(cp), 1,fb);
		fclose(fb);
		exit(0);
	}
}

void criar_lista () {
    Consulta s;
    s.tipo = -1;
    //for (int t=0; 10 < sizeof(lista_consultas)/sizeof(Consulta); t++) {
    for (int t=0; t < 10; t++) {
            lista_consultas[t]=s;
            printf("joel %d\n", t);
    }
}

int main () {
    criar_lista();
    p = getpid();
    printf ("%p\n", p);
    FILE *fb;
    fb = fopen("SrvConsultas.pid", "w");
    fprintf(fb, "%d\n", p);
    fclose(fb);
    char s[100];
    signal (SIGUSR1, receber_consulta);
	while (1);
    //signal (SIGUSR1, receber_consulta);

    //int p = getpid();
    //FILE *fb;
    //fb = fopen("SrvConsultas.pid", "a");
    //fprintf(fb, "%d", &p);
    //fclose (fb);
    //signal (SIGUSR1, receber_consulta);
    signal (SIGHUP, receber_consulta);
    signal (SIGINT, receber_consulta);
}
