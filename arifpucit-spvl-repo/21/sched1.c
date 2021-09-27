/*
*  Video Lecture: 21
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of nice() system call
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;
int main(){ 
   
   int nv = nice(+0);
   printf("Original nice value= %d\n", nv);
   nv = nice(+7); 
   printf("Incrementing by nice(+7) = %d\n", nv);
errno = 0;
   nv = nice(-2); //only root can give a negative value
   if(nv==-1 && errno != 0){
	perror("nice(-2) failed");
	exit(1);
   }   
   printf("Decrementing by nice(-2) = %d\n", nv);
   return 0;
}
