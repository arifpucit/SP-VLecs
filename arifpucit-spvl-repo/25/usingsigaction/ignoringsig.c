/*
*  Video Lecture: 25
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  The process enters in an infinite loop, and use sigaction() to ignore SIGINT and SIGFPE
*  When the user press <CTRL + C> the OS sends SIGINT<2> to the process
*  and the process ignores it and do not terminates
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
 //signal(SIGINT,SIG_IGN);
 //signal(SIGFPE, SIG_IGN);
struct sigaction newact;
newact.sa_handler = SIG_IGN;
newact.sa_flags = 0;
sigemptyset(&newact.sa_mask);
sigaction(SIGINT, &newact, NULL);
sigaction(SIGFPE, &newact, NULL);


 while(1) {
   printf("I am in an infinite loop!\n");
   printf("You can't kill me by SIGINT <2> or SIGFPE <8>\n");
   sleep(2);
 }
 return 0;
}
