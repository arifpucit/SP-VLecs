/*
*  Video Lecture: 09
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>

   void f1();
   void f2();
int main(){
   printf("I m in main.\n");
   f1();
   return 0;
}
void f1(){
   label: printf("I m in f1()\n");
   f2();
}
void f2(){
   printf("I m in f2()\n");
   goto label;
}
