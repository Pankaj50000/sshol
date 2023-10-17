// Question : Write a program to create a semaphore and initialize value to the semaphore - Create a binary semaphore

#include<unistd.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>

int main()
{
	union semum
	{
       	 	int val;        //value for SETVAL
	}arg;

	int key, semid;

	key = ftok(".", 'a');
	semid = semget(key, 1, IPC_CREAT | 0644);
	arg.val = 1;	//1 for binary, >1 for counting semaphore

	semctl(semid, 0, SETVAL, arg);

	return 0;
}
