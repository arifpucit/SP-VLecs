/*
*  Video Lecture: 21
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of sched_getscheduler() and sched_rr_get_interval()system call
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

int main(){
//get the scheduling policy of the currently running process   
   int s_policy = sched_getscheduler(getpid());
   printf("Scheduling policy of the current process = %d\n", s_policy);
//get the time slice
   struct timespec tp;
   int rv = sched_rr_get_interval(getpid(), &tp);
   if(rv == -1){
      printf("Error in getting the time slice\n");
      exit(1);
   }
   printf("Time Slice is %ld sec and %ld nanosecs \n", tp.tv_sec, tp.tv_nsec);
   return 0;
}
