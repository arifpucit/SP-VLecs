/*
*  Video Lecture: 31
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  serialize1.c: The main() creates three threads,
*  each thread displays a string
*  compile: $ gcc serialize1.c -lpthread -D_REENTRANT
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void * f1(void * arg);
int main(){
   pthread_t t1, t2, t3;
   char* msg1 = "Learning is ";
   char* msg2 = "fun with ";
   char* msg3 = "Arif Butt";
      pthread_create(&t1, NULL, f1,(void*)msg1);
      pthread_create(&t2, NULL, f1,(void*)msg2);
      pthread_create(&t3, NULL, f1,(void*)msg3);
      pthread_join(t1,NULL);
      pthread_join(t2,NULL);
      pthread_join(t3,NULL);
      printf("\n\n");
   return 0;
}
void * f1(void * arg){
   char* msg = (char*)arg;
   printf("%s", msg);
   pthread_exit(NULL);
}
