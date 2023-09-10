#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
 void main() {
	 int priority=getpriority(PRIO_PROCESS,0);
	 printf("prority of the process is %d\n",priority);
	 int prority2=nice(-5);
	 printf("New priority of the process is%d\n",prority2);
		 
 }
