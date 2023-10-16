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

        //write
        printf("Enter text : ");
        scanf("%[^\n]", data);

        //read
        printf("Text from shared memory : %s\n", data);
        getchar();

        return 0;
}
