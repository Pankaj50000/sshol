// Question : Write a program to communicate between two machines using socket
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
        struct sockaddr_in server;

        int sd;
        char buf[80];

        sd = socket(AF_UNIX, SOCK_STREAM, 0);

        server.sin_family = AF_UNIX;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(5555);

	connect(sd, (void *)(&server), sizeof(server));

	write(sd, "Hello Server\n", 14);

	read(sd, buf, sizeof(buf));
	printf("Message from Server : %s\n", buf);
	
	return 0;
}
