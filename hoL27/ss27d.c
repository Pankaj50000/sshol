#include<stdio.h>
#include<unistd.h>

int main(void) {
	char* arr[] = {"ls", "-R", "-l", NULL};
	execv("/bin/ls", arr);

	return 0;
}
