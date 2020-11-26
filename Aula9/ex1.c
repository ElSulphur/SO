#include "defines.h"
int main () {
int id;
id=msgget(IPC_KEY, 0666 | IPC_CREAT);
exit_on_error(id, "Erro no msgget");
printf("Estou a usar a fila de mensagens id=%d\n", id);
}
