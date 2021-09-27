/*
*  Video Lecture: 38
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  prog1.c: A C-program calling C-standard lib function
*  compile: gcc prog1.c
*  usage: ./a.out
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
   int rv = printf("Learning is fun with Arif\n");
   exit(rv);
}
