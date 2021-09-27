/*
*  Video Lecture: 26
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  A hello world program on pipe
*  shows the usage of a pipe withing a single process
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE  25
int main(){
   const char * msg = "Hello, World! (Using pipe) \n";
   char  buf[SIZE];
   memset(buf,'\0',SIZE);
//create a pipe
   int fd[2];
   int rv = pipe(fd);
   if (rv == -1){
	printf("\n Pipe failed");
	exit(1);
   }
//write data in the pipe using fd[1] that points to write end of pipe
   int cw = write(fd[1],msg, strlen(msg));
//read data from the pipe using fd[0] that points to read end of pipe
   int cr = read(fd[0], buf, cw);
//display the data on stdout
   write(1, buf, cr);
   while(1);
   return (0);
}
