/*
*  Video Lecture: 38
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  prog3.c: A C program calling system call w/o using C lib wrapper
*  The system call # are in file 
*  /usr/include/x86_64-linux-gnu/asm/unistd_64.h
*  compile: gcc prog3.c
*  usage: ./a.out
*/
#include <unistd.h>
#include <sys/syscall.h>
int main(){
   int rv = syscall(1, 1, "Learning is fun with Arif\n", 26);
   syscall(60, rv);
}
