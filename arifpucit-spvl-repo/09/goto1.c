/*
*  Video Lecture: 09
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>

int main(){
   printf("Start of loop.\n");
   int ctr=1;
   label1: 
   printf ("PUCIT\n");
   ctr++;
   if (ctr == 6)
      goto label2;
   goto label1;
   label2:
   printf("Out of loop\n");
   return 0;
}
