/*
*  Video Lecture: 15
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  whov0.c: Open and read UTMP file and display utmp records on stdout
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h> 

void show_info(struct utmp*);
int main(){
   int fd = open("/var/run/utmp", O_RDONLY);	
   if (fd == -1 ){
	   perror("Error in opening utmp file");
	   exit(1);
   }
   struct utmp rec;
   int reclen = sizeof(rec);
   while (read(fd, &rec, reclen) == reclen)
	   show_info(&rec);
   close(fd);
	return 0;	
}

void show_info(struct utmp *rec){
	printf("%-10.10s   ", rec->ut_user);
	printf("%-10.10s   ", rec->ut_line);
	printf("%-10.10d", rec->ut_time);
   printf("   (%s)", rec->ut_host);
	printf("\n");		
}
