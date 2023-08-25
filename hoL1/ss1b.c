#include<stdio.h>
#include<unistd.h>
int main(){
	const char* targetfile="samplefile1";
	const char* link="softlink";
	if(symlink(targetfile,link)==-1){
	perror("some error occured");
	return 1;
	}
	return 0;
}
