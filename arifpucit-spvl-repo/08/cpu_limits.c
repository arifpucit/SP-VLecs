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

int main(){
   struct rlimit limit;
   getrlimit(RLIMIT_CPU, &limit);
   printf("%s","RLIMIT_CPU");
   if (limit.rlim_cur == RLIM_INFINITY)
      printf("(infinity) ");
   else
      printf("%d ", limit.rlim_cur);

   if (limit.rlim_max == RLIM_INFINITY)
      printf("(infinity) \n");
   else
      printf("%d \n", limit.rlim_max);

   return 0;
}
