/*
*  Video Lecture: 08
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
int main(){
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) < 0)
      fprintf(stderr, "%s\n", strerror(errno));
   else
      printf("%s","RLIMIT_NPROC");

   if (limit.rlim_cur == RLIM_INFINITY)
      printf("(infinity) ");
   else
      printf(" %d ", limit.rlim_cur);

   if (limit.rlim_max == RLIM_INFINITY)
      printf("(infinity) \n");
   else
      printf(" %d \n", limit.rlim_max);

   return 0;
}	
