#include "custom_sem.h"
#include "custom_shm.h"

/***********************************************************************
    * master.c
    * Program performing withdrawals and deposits (ATM).
    * Author: Suyeon
***********************************************************************/

/* Shared memory */
int shmid;
char *shm;

/* Semaphore */
int semid;

int main(int argc, char *argv[])
{

    /* Setting up memory */
    semid = create_semaphore();
    //init_semaphore(semid);
    shmid = allocate();

    lock(semid);

    shm = attach(shmid);
    strcpy(shm, "Hello world!");
    detach(shm);

    unlock(semid);

    return 0;
}