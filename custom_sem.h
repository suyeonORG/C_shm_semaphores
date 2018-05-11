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
    * custom_sem.h
    * Author: Suyeon 
***********************************************************************/

/* Creates the semaphore */
int create_semaphore();

/* Sets semaphore value to 1 */
void init_semaphore(int semid);

/* Down */
void lock(int semid);

/* Up */
void unlock(int semid);