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
	int fd = open("/etc/passwd", O_RDONLY);
   printf("The first file descriptor is %d\n",fd);
	int rv = fcntl(fd, F_DUPFD, 54);
   printf("The duplicate file descriptor using fcntl() is %d\n",rv);
	return 0;
}
