/*
*  Video Lecture: 15
*  Programmer: Arif Butt
*  Course: System Programming with Linux
   This is a basic cp program 
*  usage: time ./a.out srcfile destfile
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFSIZE 1024
int main(int argc, char *argv[]){
   if (argc != 3)	{
      printf("Invalid number of arguments.\n");
      exit(1);
   }
   int srcfd = open (argv[1], O_RDONLY);
   int destfd = open(argv[2],O_CREAT|O_RDWR|O_TRUNC, 00600);
   char buff[BUFSIZE];
   int n = 0;
   for(;;){
   n = read (srcfd, buff, BUFSIZE);
   if (n <= 0){
      close(srcfd); 
      close(destfd); 
      return 0;
   }
   write(destfd, buff, n);
   } 
   close(srcfd);
   close(destfd);
   return 0;
}
