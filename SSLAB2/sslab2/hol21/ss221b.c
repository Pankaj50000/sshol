// Question : Write two programs so that both can communicate by FIFO - Use two way communications.
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2;
	char buf1[50], buf2[50];

	fd1 = open("myfifo", O_WRONLY);
	fd2 = open("myfifo1", O_RDONLY);

	printf("Enter the text : ");
	scanf("%[^\n]", buf1);

	write(fd1, buf1, sizeof(buf1));

	read(fd2, buf2, sizeof(buf2));
	printf("Text from myfifo1 : %s\n", buf2);

	return 0;
}
