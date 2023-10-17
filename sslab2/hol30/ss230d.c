#include<sys/shm.h>
#include<stdio.h>

int main()
{
        int shmid;
        key_t key;
        char *data;

	struct shmid_ds shm;

        key = ftok(".", 'c');
        shmid = shmget(key, 1024, 0);
        data = shmat(shmid, 0, SHM_RDONLY);

        //remove shm
	shmctl(shmid, IPC_RMID, &shm);
	perror(" ");

        return 0;
}
