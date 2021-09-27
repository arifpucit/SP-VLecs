/*
*  Video Lecture: 13
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
extern int errno;
int  main(){
   int rv = lseek(0, 54, SEEK_SET);
   if (rv == -1){
      printf("Cannot seek\n");
      exit(errno);
   }
   else
      printf("seek OK\n");
   return 0;
}
