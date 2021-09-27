/*
*  Video Lecture: 38
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  prog2.c: A C-program calling system call using C lib wrapper
*  compile: gcc prog2.c
*  usage: ./a.out
*/
#include <unistd.h>
#include <stdlib.h>
int main(){
   int rv = write(1, "Learning is fun with Arif\n", 26);
   exit(rv);
}
