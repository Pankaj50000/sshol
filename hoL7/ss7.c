#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
         int srcfd,destfd;
         char buffer[1024];
         ssize_t bytesread,byteswrote;
         srcfd=open("inputfile",O_RDONLY);
         if(srcfd==-1){
	            printf("error opening target file..");
	            return 1;
	            }
	 destfd=open("targetfile",O_WRONLY | O_CREAT | O_TRUNC);
	 if(destfd==-1){
	 printf("error opening target file..");
	 }
         while((bytesread=read(srcfd,buffer,sizeof(buffer)))>0){
	    byteswrote=write(destfd,buffer,bytesread);
	  if(byteswrote==-1){
	    close(srcfd);
	  close(destfd);
	  return 1;
	  }
	 }
        close(srcfd);
        close(destfd);
         
        printf("data copied successfully from inputfile to target file..");
         return 0;
      
         }
