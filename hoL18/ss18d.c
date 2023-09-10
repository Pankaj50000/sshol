#include<unistd.h>
#include<fcntl.h>

int main(void) {
	int fd = open("18Record", O_RDWR | O_CREAT, 0600);
	struct student {
		char* name;
		int roll_no;
	} a;

	for(int i = 1; i <= 3; i++) {
		a.name = "A";
		a.roll_no = i;
		write(fd, &a, sizeof(a));
	}

	return 0;
}
