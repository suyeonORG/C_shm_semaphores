#################################################################
# Makefile
#################################################################
CFLAGS = -std=c11 -w -pedantic -g

#slave
slave : slave.o custom_sem.o custom_shm.o
	cc $(CFLAGS) -o slave slave.o custom_sem.o custom_shm.o
	make clean

slave.o : custom_sem.h custom_shm.h
	cc $(CFLAGS) -c slave.c

#master
master : master.o custom_sem.o custom_shm.o
	cc $(CFLAGS) -o master master.o custom_sem.o custom_shm.o
	make clean

master.o : custom_sem.h custom_shm.h
	cc $(CFLAGS) -c master.c

#all
custom_sem.o : custom_sem.h
	cc $(CFLAGS) -c custom_sem.c

custom_shm.o : custom_shm.h
	cc $(CFLAGS) -c custom_shm.c

#clean
clean :
	rm *.o

#reset
reset :
	rm master
	rm slave