/*
*  Video Lecture: 21
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of getpriority() and setpriority() system calls
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
extern int errno;
int main(){ 
//get the nice value of calling process
   int nv = getpriority(PRIO_PROCESS, 0);
   printf("nice value of calling process = %d\n", nv);

//get the nice value of another process, e.g., parent process
   nv = getpriority(PRIO_PROCESS, getppid());
   printf("nice value of parent process = %d\n", nv);

//get the maximum possible nice value of process group of the calling process
   nv = getpriority(PRIO_PGRP, 0);
   printf("maximum nice value in calling Process Group = %d\n", nv);

//get the maximum possible nice value of user group of the calling process
   nv = getpriority(PRIO_USER, 0);
   printf("maximum nice value in the user group = %d\n", nv);

//change the nice value of calling process
errno = 0;
   nv = setpriority(PRIO_PROCESS, 0, -2);
   if(nv==-1 && errno != 0){
	perror("setpriority(PRIO_PROCESS, 0, -2) failed");
	exit(1);
   }   
   nv = getpriority(PRIO_PROCESS, 0);
   printf("nice value after setpriority(PRIO_PROCESS, 0 , -2) = %d\n", nv);
   return 0;
}
