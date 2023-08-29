#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd=open("ticketfile",O_EXCL|O_RDWR);
	printf("%d\n",fd);
	struct flock lock;
	int train=-1;
	printf("enter train number to book (1,2,3)");
	scanf("%d",&train);
	if(train!=1&&train!=2&&train!=3)
	{
		printf("train number invalid\n");
		return 0;
	}
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(train-1)*3;
	lock.l_len=2;
	lock.l_pid=getpid();
	int l=fcntl(fd,F_SETLKW,&lock);
	lseek(fd,(train-1)*3,SEEK_SET);
	//printf("%d\n",l);
	char buff[3]={'0','0','\0'};
	read(fd,buff,2);
	int available=(buff[0]-'0')*10+(buff[1]-'0');
	//printf("available - %d\n",available);
	if(available>0)
	{
		printf("press enter to confirm\n");
		getchar();
		getchar();
		available--;
		buff[0]='0'+(available/10);
		buff[1]='0'+(available%10);
		lseek(fd,(train-1)*3,SEEK_SET);
		write(fd,buff,2);
		lock.l_type=F_UNLCK;
		fcntl(fd,F_SETLKW,&lock);
		printf("Ticket number %d in train %d booked\n",available+1,train);
	}
	else
	{
		printf("tickets not available\n");
	}
	return 0;
}
