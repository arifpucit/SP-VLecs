/*
*  Video Lecture: 27
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Program creates a named pipe, myfifo and
*  opens it in read mode and continuously reads from myfifo 
*  and displays the characters read on stdout as well
*  usage: ./reader
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
   int num;   
   mknod("myfifo", S_IFIFO | 0666, 0);
   printf("Waiting for writers....\n");
   int readfd = open("myfifo", O_RDONLY);
   printf("Got a writer\n");
   do{//keep reading from myfifo
      num = read(readfd, buff, 1024);
      buff[num] = '\0';
      //display the contents on stdout
      printf("Reader read %d bytes: %s\n",num, buff);
   }while(num > 0); // read until EOF 
   return 0; 
}
