/*
*  Video Lecture: 10
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MB 1024*1024
int main(){
   char* ptr = NULL;
   int ctr = 0;
   while (1){
      ptr = (char *) malloc(MB);
//      memset(ptr,'\0', MB);
      printf("Currently allocating %d MB\n", ++ctr);
   }
   exit(0);
}
