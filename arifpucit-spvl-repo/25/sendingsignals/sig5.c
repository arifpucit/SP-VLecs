/*
*  Video Lecture: 25
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of alarm system call
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
int main(){
   int i = alarm(205);
   printf("i contains: %d\n", i);
   sleep(5);
   int j = alarm(10);
   printf("After alarm(10); j contains: %d\n", j);
   sleep(100);
   exit(0);
}
