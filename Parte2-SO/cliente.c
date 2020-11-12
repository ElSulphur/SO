#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "consulta.h"
//#include <stdlib.h>
//#include <signal.h>
//#include <unistd.h> para a função alarm()

Consulta nova_consulta() {
    Consulta n;
    printf("Tipos de consulta:\n");
    printf("1-Normal, 2-COVID19, 3-Urgente\n");
    printf("Qual é o tipo de consulta?\n");
	scanf("%d", &n.tipo);
	printf("Qual é a descrição da consulta?\n");
	scanf("%s", n.descricao);
    n.pid_consulta=getpid();
    printf ("%d\n", n.pid_consulta);
	//return n;
    FILE *ft=fopen("PedidoConsulta.txt", "a");
    fprintf(ft, "%d %s\n", n.tipo, n.descricao);
    fclose(ft);
    return n;
}

void trata_sinal (int sinal) {
    //SIGUSR2 é 12
    if (sinal == SIGUSR2) {
        printf ("Consulta não é possível para o processo <pid_consulta>");
        remove("PedidoConsulta.txt");
        exit (-1);
    }
    //SIGHUP é 1
    if (sinal == SIGHUP) {
        printf ("Consulta iniciada para o processo <pid_consulta>");
        remove("PedidoConsula.txt");
        //pause() ??
    }
    if (sinal == SIGTERM) {
        int i;
        //usar o fork
        i=fork();
        if (i == SIGHUP) {
            printf ("Consulta concluída para o processo <pid_consulta>");
        } else {
            printf ("Não foi iniciada nenhuma consulta!");
        }
    }
}


int main () {
    Consulta new;
    new=nova_consulta();

}