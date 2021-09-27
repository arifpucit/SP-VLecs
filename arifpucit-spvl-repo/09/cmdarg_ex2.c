/*
*  Video Lecture: 09
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
   if (strcmp(argv[0], "./hello")==0)
      printf("I am called by the name hello\n");
   else
      printf("I am called by the name bye\n");
   return 0;

}
