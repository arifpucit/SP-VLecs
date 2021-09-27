/*
*  Video Lecture: 22
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  temp2.c: It executes another program of user choice using execvp()
*  The command and its one argument is received from user
*  The size of the command string as well as the arument string
*  is assumed to be fixed and is of 10 Bytes
*/

#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
int main(){
 printf("You must enter only a command and one argument:\n");
   char *arglist[3];
   for(int i =0; i< 3; i++)
      arglist[i] = (char*)malloc(sizeof(char)*10);

   printf("arglist[0]: ");
   scanf("%s", arglist[0]);
   printf("arglist[1]: ");
   scanf("%s", arglist[1]);
   arglist[2] = NULL;
   execvp(arglist[0], arglist);
   perror("Exec failed");
   return 0;
}
