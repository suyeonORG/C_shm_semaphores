#include "custom_sem.h"
#include "custom_shm.h"

/***********************************************************************
    * slave.c
    * Program performing maintenance operations on the account table.
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
    init_semaphore(semid);
    shmid = allocate();

    /* Selecting options */
    if (argc == 2)
    {
        lock_for(atoi(argv[1]), semid);
    }
    // to clear the memory
    //clear(shmid);
    return 0;
}

void lock_for(int delay, int semid)
{
    printf("\n--- BEGIN LOCK ---\n");
    lock(semid);
    shm = attach(shmid);
    sleep(delay);
    printf("\n--- MESSAGE: ---");
    printf("\n--- %s ---\n\n", shm);
    detach(shm);
    unlock(semid);
    printf("--- LOCKED FOR %d SECONDS ---\n", delay);
}