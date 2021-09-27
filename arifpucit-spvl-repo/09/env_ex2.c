/*
*  Video Lecture: 09
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main()
{

    printf("\n Environment variable passed are:\n");
   for (int i = 0; environ[i] != NULL ; i++)
      printf("environ[%d]:%s\n", i, environ[i]);

   return 0;

}
