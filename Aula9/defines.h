#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#define exit_on_error(s,m) if (s<0) { perror(m); exit(1);}
#define IPC_KEY 0x0a92608

