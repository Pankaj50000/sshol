#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
 void main(){
         int childpid,fd;
	 char *filename="samplefile.txt";
         fd=open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
         if((childpid=fork())!=0)
             write(fd,"this is parent/n",16);
         else
             write(fd,"this is child/n",16);
	 close(fd);
 }
