#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <string.h>
#include "config.h"

/***********************************************************************
    * custom_shm.h
    * Author: Suyeon
***********************************************************************/

int *allocate();

char *attach(int shmid);

void detach(void *memory);

void clear(int shmid);