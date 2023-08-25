#include<fcntl.h>
#include<stdio.h>
int main(){
	mode_t mode=S_IRUSR | S_IRGRP | S_IROTH;
	int fdescval=creat("testfile",mode);
	if(fdescval==-1)
		printf("error in creating file.");
	else
		printf("file discriptor value:%d",fdescval);

}
