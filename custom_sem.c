#include "custom_sem.h"

/***********************************************************************
    * custom_sem.h
    * Managing semaphores.
    * Author: Suyeon
***********************************************************************/

struct sembuf sem;
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

void lock(int semid)
{
    sem.sem_op = -1;
    sem.sem_num = 0;
    sem.sem_flg = 0;
    SYS(semop(semid, &sem, 1));
    printf("Semaphore %d is 'locked'\n", semid);
}

void unlock(int semid)
{
    sem.sem_op = 1;
    sem.sem_num = 0;
    sem.sem_flg = 0;
    SYS(semop(semid, &sem, 1));
    printf("Semaphore %d is 'unlocked'\n", semid);
}

int create_semaphore()
{
    int semid = semget(SEMAPHORE_KEY, 1, IPC_CREAT | 0660);
    printf("Semaphore created. semid = %d\n", semid);
    return semid;
}

void init_semaphore(int semid)
{
    union semun sem_union;
    sem_union.val = 1;
    SYS(semctl(semid, 0, SETVAL, sem_union));
    printf("Semaphore %d initialized\n", semid);
}