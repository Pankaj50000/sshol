#include<stdio.h>
#include<unistd.h>
#include<wait.h>
int main(){
        if(!fork()){
	printf("process id of child process is %d\n",getpid());
	printf("process id of parent seen from child%d\n",getppid());
	}
       else {
       printf("process id of parent process is%d\n",getpid());
       wait(0);
       }

       }
