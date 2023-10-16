// Question : Write a program to receive messages from the message queue with `IPC_NOWAIT` as a flag

#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>

int main()
{
        int msgid, size;
        key_t key;

        struct msg
        {
                long int mtype;
                char message[50];
        }mq;

        key = ftok(".", 'b');
        msgid = msgget(key, 0);

        printf("Enter msg type to receive : ");
        scanf("%ld", &mq.mtype);

        msgrcv(msgid, &mq, sizeof(mq.message), mq.mtype, IPC_NOWAIT);

        printf("Message type : %ld", mq.mtype);
        perror(" ");
        printf("\nMessage text : %s\n", mq.message);

        return 0;
}
