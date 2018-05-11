#include "custom_shm.h"

/***********************************************************************
    * custom_shm.c
    * Methods handling shared memory.
    * Author: Suyeon
***********************************************************************/

int *allocate()
{
    int shmid = shmget(MEMORY_KEY, SIZE * sizeof(char), IPC_CREAT | 0660);
    printf("Memory allocated at %d\n", shmid);
    return shmid;
}

char *attach(int shmid)
{
    printf("Memory attached!\n");
    return shmat(shmid, NULL, SHM_R | SHM_W);
}

void detach(void *memory)
{
    printf("Memory detached!\n");
    shmdt(memory);
}

void clear(int shmid)
{
    SYS(shmctl(shmid, IPC_RMID, NULL));
    printf("Memory cleared. shmid %d\n", shmid);
}