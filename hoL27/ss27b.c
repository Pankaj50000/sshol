#include<stdio.h>
#include<unistd.h>

int main(void) {
	execlp("ls", "ls", "-R", "-l", NULL);

	return 0;
}
