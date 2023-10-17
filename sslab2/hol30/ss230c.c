#include<sys/shm.h>
#include<stdio.h>

int main()
{
        int shmid;
        key_t key;
        char *data;

        key = ftok(".", 'c');
        shmid = shmget(key, 1024, 0);
        data = shmat(shmid, 0, SHM_RDONLY);

        //detach
	shmdt(data);
	perror(" ");

        return 0;
}
