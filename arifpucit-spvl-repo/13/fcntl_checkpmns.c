/*
*  Video Lecture: 13
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char * argv[]){
   int accmode, flags;
   int fd = open(argv[1], O_RDONLY);
   flags = fcntl(fd, F_GETFL, 0);
   flags = flags & O_ACCMODE;
   if (flags == O_RDONLY) printf("read only\n");    
   else if (flags == O_WRONLY) printf("write only\n");    
   else if (flags == O_RDWR) printf("read write\n");    
   else printf("Unknown access mode\n");
   return 0;
}
