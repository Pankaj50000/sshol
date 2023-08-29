#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
        char fpath[]="samplefile";
        struct stat fileinfo;

        if(stat(fpath,&fileinfo)==0){
	        printf("Inode is:%lu\n",fileinfo.st_ino);
	        printf("no. of hard links is:%lu\n",fileinfo.st_nlink);
	        printf("UID :%u\n",fileinfo.st_uid);
		 printf("GID :%u\n",fileinfo.st_gid);
		 printf("Size is :%ld\n",fileinfo.st_size);
	        printf("Block is :%ld\n",fileinfo.st_blocks);
		 printf("Block Size is :%ld\n",fileinfo.st_blksize);
		  printf("Time of last access :%ld\n",fileinfo.st_atime);
		printf("Time of last modification :%ld\n",fileinfo.st_mtime);
	       printf("Time of last change :%ld\n",fileinfo.st_ctime);
	}
    
      }
