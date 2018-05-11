#include <stdlib.h>

/***********************************************************************
    * config.h
    * Author: Suyeon
***********************************************************************/

#define SYS(call) (call == -1 ? perror("SYSCALL ERROR"), exit(1) : 0)

#define MEMORY_KEY 9994
#define SEMAPHORE_KEY 8886
#define SIZE 15