#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for STDIN_FILNO
#include <fcntl.h>
int main()
{
   char buff[256];
   int fd = open("data.txt",O_RDONLY);
   int n = pread (fd, buff, 255,5);
   write(STDOUT_FILENO, buff, n); 
   return 0;

}
