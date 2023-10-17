// Question : Write a program to wait for data to be written into FIFO within 10 seconds, use `select` system call with FIFO.
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
	char buf[1024];
	int nfds = 1;
	fd_set rfd;
	struct timeval timeout;
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;
	
	int fd = open("20_FIFO", O_RDONLY);
	FD_ZERO(&rfd);
	FD_SET(fd, &rfd);
	int rd = read(fd, buf, sizeof(buf));
	int slct = select(nfds, &rfd, NULL, NULL, &timeout);
	if(slct == 0)
	{
		printf("No data received within 10 sec.\n");
	}
	else
	{	
		printf("Msg received : %s\n", buf);
	}
	return 0;
}
