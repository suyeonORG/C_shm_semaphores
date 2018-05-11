# Semaphore and Shared memory example
[C] Simple semaphore/shared memory implementation
![](suyeon.svg)

# How to use
The following example is silly and stupid. The goal here is to use the methods in your own solution.
Simply use the makefile to generate the two compiled examples. 'make master' and 'make slave'.
Two executables will then appear. Simply start with the master by executing it './master'.
The master is supposed to write a string in the shared memory.
The slave is supposed to get what the master said and repeat it after a certain delay.
To execute the slave you must use the following command './slave DELAY' where DELAY is an integer.

# Concurrency
Execute the slave first with './slave 15' then execute the './master'. You would notice that now the master needs to wait until the slave is done.