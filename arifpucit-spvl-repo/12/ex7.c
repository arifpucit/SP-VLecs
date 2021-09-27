/* file3.c
   Programmer's name: Arif Butt
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
  int n; char buff[1024];
  
  umask(0);
  int fd = open("newdatafile.txt",O_CREAT|O_TRUNC|O_RDWR,0666); //file opened in write mode
  if (fd == -1) {printf("Error in creating file\n"); exit(1);}
   for(;;)
   {
      n = read (0, buff, 1023);
      if (n<=0)    
      {
         printf("Error in reading source file.\n");
	 exit(-n);
      }
      write(fd, buff, n);
   }
   close(fd);
   return 0;
}
