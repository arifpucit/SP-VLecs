/*
*  Video Lecture: 15
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  whov2.c: hides the non user records from utmp file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h> 
#include <time.h>

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
   if(rec->ut_type != 7)
      return;
	printf("%-10.10s   ", rec->ut_user);
	printf("%-10.10s   ", rec->ut_line);
   long time = rec->ut_time;
   char* dtg = ctime(&time);
	printf("%-15.12s", dtg+4);
   printf("   (%s)", rec->ut_host);
	printf("\n");		
}
