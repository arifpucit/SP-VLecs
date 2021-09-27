/*
*  Video Lecture: 31
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  shareddata.c:
*  compile: $ gcc shareddata.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
char** ptr;
void * thread_function(void * localarg);
int main(){
   pthread_t tid[2];
   char* msg[2] = {"Hello from Arif", "Hello from PUCIT"};
   ptr = msg;
   for(int i=0;i<2;i++){
      pthread_create(&tid[i], NULL, thread_function, (void*)&i);
      pthread_join(tid[i], NULL);
   }
   return 0;
}
void * thread_function(void * localarg){
   int myid = *((int*)localarg);
   static int svar = 0;
   printf("[%d]: %s (svar = %d)\n", myid, ptr[myid], ++svar);
   pthread_exit(NULL);
}
