// Question : Write a program to wait for data to be written into FIFO within 10 seconds, use `select` system call with FIFO.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char buf[1024];
	int fd = open("20_FIFO", O_WRONLY);
	printf("Write the msg : ");
	scanf(" %[^\n]", buf);
	int wr = write(fd, buf, sizeof(buf));
	return 0;
}
