#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "consulta.h"
//#include <stdlib.h>
//#include <signal.h>
//#include <unistd.h> para a função alarm()

int b;
int veracidade=0;

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
    FILE *fb;
    if ((fb = fopen("PedidoConsulta.txt", "r"))) {
        fclose(fb);
        printf("Erro! Ficheiro PedidoConsulta.txt não está vazio!\n");
        alarm(10);
        FILE *ft=fopen("PedidoConsulta.txt", "a");
        fprintf(ft, "%d %s %d\n", n.tipo, n.descricao, n.pid_consulta);
        fclose(ft);
    } else {
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
        b = atoi(a);
        //printf ("%d\n", b);
        fclose (fp);
        kill (b, SIGUSR1);
        //return n;
    }
}

void trata_sinal (int sinal) {
    //SIGUSR2 é 12
    if (sinal == 12) {
        printf ("Consulta não é possível para o processo %d\n", getpid());
        remove("PedidoConsulta.txt");
        exit (-1);
    }
    //SIGHUP é 1
    if (sinal == 1) {
        veracidade=1;
        printf ("Consulta iniciada para o processo %d\n", getpid());
        remove("PedidoConsula.txt");
        //int status;
        //waitpid(getpid(), &status, 0);
        //pause() ??
    }
    //SIGTERM é 15
    if ((sinal == 15) && (veracidade == 1)) {
        printf ("Consulta concluída para o processo %d\n", getpid());
        //printf ("Não foi iniciada nenhuma consulta!");
        nova_consulta();
    }
    //SIGINT é 2
    if (sinal == SIGINT) {
        printf ("O cliente cancelou o pedido!\n");
        remove ("PedidoConsulta.txt");
        exit (0);
    }
}

int main () {
    //Consulta new;
    //new=nova_consulta();
    //temporario
    remove ("PedidoConsulta.txt");
    nova_consulta();
   // FILE *fb;
  //  int pid;
   // fb = fopen("SrvConsultas.pid", "r");
  // fscanf(fb, "%d", &pid);
   // fclose (fb);
    //kill (-pid, SIGUSR1);
    char s[100];
    signal (SIGHUP, trata_sinal);
    signal (SIGTERM, trata_sinal);
    signal (SIGUSR2, trata_sinal);
    signal (SIGINT, trata_sinal);
	while (1);
}