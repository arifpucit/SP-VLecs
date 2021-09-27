/*
*  Video Lecture: 25
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  The process creates a handler and mask all the signals,
*  while the handler code is being executed
*  This is done using sigaction()
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
void  myhandler(int signum){
   printf("Hey, I got signal: %d\n",signum);
   for(int i=1; i<=10; i++){
	printf("I am masking SIGINT for 10 seconds!\n");
	sleep(1);
   }
   printf("Done with the handler function and falling back to main() after 2 secs\n\n");
   sleep(2);
}

int main(){
   struct sigaction newact;
   newact.sa_handler = myhandler;
   newact.sa_flags = 0;
   sigfillset(&newact.sa_mask);
//   sigemptyset(&newact.sa_mask);
   sigaction(SIGINT, &newact, NULL);

   while(1) {
	printf("I am main() in an infinite loop!\n");
	sleep(1);
   }
   return 0;
}
