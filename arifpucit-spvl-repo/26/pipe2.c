/*
*  Video Lecture: 26
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of pipe between two related processes
*  child is a reader process while parent is a writer process
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 1024
int main(){
   int fd[2];
   int rv = pipe(fd);
//create a child process
   pid_t cpid = fork();
//parent code (parent is writer process)
   if (cpid != 0) {
      close(fd[0]);
      const char * msg = "Welcome to Communication using pipes\n";
      write(fd[1], msg,strlen(msg));
      waitpid(cpid, NULL, 0);
      exit(0);
   }
//child code (child is reader process)
   else { 
      close(fd[1]);
      char buff[SIZE];
      memset(buff, '\0',SIZE);
      fprintf(stderr,"Message sent from parent is: "); 
      int n = read(fd[0],buff,SIZE);
      write(1,buff,n);   
      exit(0);
   }
}
