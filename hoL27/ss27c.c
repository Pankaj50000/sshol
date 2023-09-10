#include<stdio.h>
#include<unistd.h>

int main(void) {
	char* envp[] = {NULL};
	execle("/bin/ls", "ls", "-R", "-l", NULL, envp);

	return 0;
}
