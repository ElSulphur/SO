#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "consulta.h"
//#include <stdlib.h>
//#include <signal.h>
//#include <unistd.h> para a função alarm()

//Consulta nova_consulta() {
void nova_consulta() {
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
    fprintf(ft, "%d %s %d\n", n.tipo, n.descricao, n.pid_consulta);
    fclose(ft);
    FILE *fp;
    fp = fopen("SrvConsultas.pid", "r");
    //if (fp == NULL) {
    //    perror("Erro");
    //    exit(1);
    //}
    char a[50];
    fgets(a, sizeof(a), fp);
    //atoi semelhante ao (int) (char) em java
    int b = atoi(a);
    kill (b, SIGUSR1);
    fclose (fp);
    //return n;
}

void trata_sinal (int sinal) {
    //SIGUSR2 é 12
    if (sinal == SIGUSR2) {
        printf ("Consulta não é possível para o processo %d\n", getpid());
        remove("PedidoConsulta.txt");
        exit (-1);
    }
    //SIGHUP é 1
    if (sinal == SIGHUP) {
        printf ("Consulta iniciada para o processo %d\n", getpid());
        remove("PedidoConsula.txt");
        //pause() ??
    }
    if (sinal == SIGTERM) {
        int i;
        //usar o fork
        i=fork();
        if (i == SIGHUP) {
            printf ("Consulta concluída para o processo %d\n", getpid());
        } else {
            printf ("Não foi iniciada nenhuma consulta!");
        }
    }
}

int main () {
    //Consulta new;
    //new=nova_consulta();
    nova_consulta();
    FILE *fb;
    int pid;
    fb = fopen("SrvConsultas.pid", "r");
    fscanf(fb, "%d", &pid);
    fclose (fb);
    //kill (-pid, SIGUSR1);
    signal (SIGHUP, trata_sinal);
    signal (SIGTERM, trata_sinal);
    signal (SIGUSR2, trata_sinal);
}