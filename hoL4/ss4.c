#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
          int main(){
	            int fdval=open("existingfile",O_RDWR | O_EXCL,0600);
	            if(fdval==-1){
		          if(errno==EEXIST)
		             printf("file already exists.");
			  else 
		             printf("error opening file.");
		    }
	            else
	            printf("file opened succesfully.");
	            return 0;
	  
	  }
