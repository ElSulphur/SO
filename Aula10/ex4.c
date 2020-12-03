#include "defines.h"


int main () {
	int id = semget(9260, 5, IPC_CREAT | 0666);
	exit_on_error(id, "semget");
	int status = semctl(id, 0, SETVAL, 1);
	exit_on_error(status, "SETVAL");
}


