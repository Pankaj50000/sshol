// Question : Write two programs so that both can communicate by FIFO - Use two way communications.

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2;
	char buf1[50], buf2[50];

	fd1 = open("myfifo", O_RDONLY);
	fd2 = open("myfifo1", O_WRONLY);

	read(fd1, buf1, sizeof(buf1));
	printf("Text from myfifo : %s\n", buf1);

	printf("Enter the text : ");
        scanf("%[^\n]", buf2);

        write(fd2, buf2, sizeof(buf2));

	return 0;
}
