/*
*  Video Lecture: 27
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Program creates a named pipe, myfifo and
*  opens it in write mode and 
*  gets input from user and continuously writes in myfifo
*  usage: ./writer
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
   char buff[1024];  
   mknod("myfifo", S_IFIFO | 0666, 0);
   printf("Waiting for readers....\n");
   int writefd = open("myfifo", O_WRONLY);
   printf("Got a reader -- type some text to be sent\n");
   //read from stdin and write to the fifo
   while(fgets(buff, 1023, stdin)) 
      write(writefd, buff, strlen(buff));
   return 0;  
}
