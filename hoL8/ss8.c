#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){
         char buffer[1];
          int fd;
         if(argc!=2){
	       printf("enter filename to read from");
	        return 1;}
          char *flname=argv[1];
           fd=open(flname,O_RDONLY);

          if(fd==-1){
	             perror("failed to open file..");
	            return 1;
	  }

         ssize_t bytesread;
         char linebuffer[1000];
         int ind=0;

         while((bytesread=read(fd,&buffer,sizeof(buffer)))>0){
	 
	       if(buffer[0]=='\n'){
	        linebuffer[ind]='\n';
		printf("%s\n",linebuffer);
		sleep(0.5);
		ind=0;
	       }
	       else{
	         linebuffer[ind]=buffer[0];
  	       ind++;}
       	  }   
	 close(fd);
	 return 0;
  
   }

