/*
*  Video Lecture: 21
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of sched_get_priority_min() system call
*/

#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main(){
   
   int min = sched_get_priority_min(SCHED_RR);
   printf("Minimum priority value for SCHED_RR = %d\n", min);
   int max = sched_get_priority_max(SCHED_RR);
   printf("Maximum priority value for SCHED_RR = %d\n", max);
   
   min = sched_get_priority_min(SCHED_FIFO);
   printf("Minimum priority value for SCHED_FIFO = %d\n", min);
   max = sched_get_priority_max(SCHED_FIFO);
   printf("Maximum priority value for SCHED_FIFO = %d\n", max);

   min = sched_get_priority_min(SCHED_OTHER);
   printf("Minimum priority value for SCHED_OTHER = %d\n", min);
   max = sched_get_priority_max(SCHED_OTHER);
   printf("Maximum priority value for SCHED_OTHER = %d\n", max);
   return 0;
}
