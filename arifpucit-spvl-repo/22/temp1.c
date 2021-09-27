/*
*  Video Lecture: 22
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  temp1.c: It executes another program ls using execvp()
*/

#include <stdio.h>
#include <unistd.h>
int main(){
   char	*arglist[4];
   arglist[0] = "ls";
   arglist[1] = "-l";
   arglist[2] = "/home";
   arglist[3] = NULL;
   execvp(arglist[0], arglist);
   return 0;
}
