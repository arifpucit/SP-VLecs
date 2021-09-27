/*
*  Video Lecture: 22
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  temp3.c: It executes another program of user choice using execvp()
*  The command and its one argument is received from user
*  This version enhances the previous version by asking the user 
*  the total number of arguments he/she wants to enter
*  and then allocates memory for that much number of arguments
*  After getting the specified number of arguments calls execvp
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   int maxargs;
   printf("How many arguments you want to enter(including the cmd): ");
   scanf("%d", &maxargs);
   char	**arglist = (char**)malloc(sizeof(char*)* (maxargs+1));
   for(int i =0; i< maxargs+1; i++)
      arglist[i] = (char*)malloc(sizeof(char)*10);

   int i =0;
   while(i<maxargs){
      printf("arglist[%d]: ", i);
      scanf("%s", arglist[i]);
      i++;
   }
   arglist[i] = NULL;
   execvp(arglist[0], arglist);
   perror("Exec failed");
   return 0;
}
