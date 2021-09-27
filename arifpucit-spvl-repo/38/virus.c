/*
*  Video Lecture: 38
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  virus.c: A sample program showing changing the 
*  control flow by manually setting the value of rip
*  compile: gcc -ggdb virus.c
*  usage: ./a.out
*/

#include <stdio.h>
#include <stdlib.h>
void f3(){ return;}
void f2(){ f3();  }
void f1(){ f2();  }
int main(){
   f1();
   return 0;
}
int virus(){
   printf("Let us Hack Planet Earth with Arif Butt.\n");
   exit(0);
}
