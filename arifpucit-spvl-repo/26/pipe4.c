/*
*  Video Lecture: 26
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  A program that simulate following shell command
*  cat f1.txt | wc -l
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
   int fd[2];
   pipe(fd);
   pid_t cpid = fork();
   if (cpid != 0){  //parent process
      dup2(fd[1], 1); //redirect stdout to write end of pipe
      close(fd[0]); //not required so better close it
      execlp("cat","mycat", "f1.txt", NULL);
   }
   else{  //child process
      dup2(fd[0], 0); //redirect stdin to read end of pipe
      close(fd[1]);  //not required so better close it
      execlp("wc","mywc", NULL);
   }
}
