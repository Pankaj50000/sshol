#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void) {
	int fd = open("samplefile", O_WRONLY);
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();

	printf("Before locking file\n");
	fcntl(fd, F_SETLKW, &fl);
	printf("Inside critical section\n");
	fl.l_type = F_UNLCK;
	printf("Press any key to unlock file\n");
	getchar();
	fcntl(fd, F_SETLK, &fl);
	return 0;}
