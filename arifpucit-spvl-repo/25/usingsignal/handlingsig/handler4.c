/*
*  Video Lecture: 25
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Hanndling a signal a specified number of times
*  and then go by the default handler
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#define TOTAL 5

void  myhandler(int signum){
   static int count = 0;
   count++;
   printf("\nDon't do it again\n");
   fflush(stdout);
   if(count >= TOTAL){
       printf("Well, if you insist, do it again and I will die!\n");
       fflush(stdout);
       signal(SIGINT, SIG_DFL);
   }
}

int main(){
   signal(SIGINT,myhandler);
   while(1);
   return 0;
}
