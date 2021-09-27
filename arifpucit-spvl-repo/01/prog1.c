/*
*  Video Lecture: 01
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
int main(){ 
   int c;
   while ((c = getchar()) != EOF)
      putchar(c);
   return 0;
}
