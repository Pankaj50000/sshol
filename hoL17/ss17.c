#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void) {
	struct flock fl;
	int fd = open("train", O_RDWR);
	if (fd == -1) {
		printf("Error");
		return 0;
	}
	struct train {
		int train_no;
		int ticket_no;
	} record;

	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = sizeof(struct train);
	fl.l_pid = getpid();

	printf("Waiting for lock\n");

	fcntl(fd, F_SETLKW, &fl);
	read(fd, &record, sizeof(record));
	lseek(fd, -sizeof(record), SEEK_CUR);
	record.ticket_no++;
	printf("Ticket number: %d\n", record.ticket_no);
	write(fd, &record, sizeof(record));

	fl.l_type = F_UNLCK;
	printf("Press any key to unlock");
	getchar();
	fcntl(fd, F_SETLK, &fl);

	return 0;
}
