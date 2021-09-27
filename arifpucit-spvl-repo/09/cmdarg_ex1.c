/*
*  Video Lecture: 09
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int i;
   printf("No of arguments passed are: %d\n",argc);
   printf("Parameters are:\n");
   for (i = 0; argv[i] != NULL ; i++)
      printf("argv[%d]:%s \n", i, argv[i]);
   return 0;

}
