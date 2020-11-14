#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "consulta.h"

int c1=0;
int c2=0;
int c3=0;
//consulta perdida
int cp=0;
Consulta lista_consultas[10];

void receber_consulta (int signal) {
    if (signal = SIGUSR1) {
        Consulta n;
        FILE *ft=fopen("PedidoConsulta.txt", "a");
        fscanf(ft, "%d %s\n", n.tipo, n.descricao);
        fclose(ft); 
        printf("Chegou novo pedido de consulta do tipo %d, descricao %s e PID <pid_consulta>\n", &n.tipo, n.descricao);
        int i=c1+c2+c3;
        if ((c1+c2+c3) > 10) {
            lista_consultas[i]=n;

        } else {
            printf("Lista de consultas cheias\n");
            //mandar o signal SIGUSR2 ao processo <pid_consulta>
            cp++;
        }
    }


}

int main () {
    int p = getpid();
    FILE *fb;
    fb = fopen("SrvConsultas.pid", "a");
    fprintf(fb, "%d", &p);
    fclose (fb);
    signal (SIGUSR1, receber_consulta);
    signal (SIGHUP, receber_consulta);
}
