/*
*  Video Lecture: 13
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h> // for exit
#include <unistd.h> //for sleep
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
   int fd = open("fcntl_lock.c", O_WRONLY);
   struct flock lock;
   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 0;
   lock.l_pid = getpid();
   int rv = fcntl(fd, F_SETLK, &lock);
   if (rv == -1){
      printf("Lock can't be acquired\n");
      exit(1);
   }
   printf("File is successfully locked ...\n");
   while(1){}
}
