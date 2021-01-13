#ifndef __defines_h__
#define __defines_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define exit_on_error(s,m) if (s<0) { perror(m); exit(1);}
#define IPC_KEY 0x92608

#endif