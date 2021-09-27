/*
*  Video Lecture: 39
*  Instructor: Arif Butt
*  Course: System Programming with Linux
*  exit_shellcode.c: The shell code executes exit() system call
*  Compile: gcc exit_shellcode.c
*  usage: ./a.out 
*/
#include <stdio.h>
#include <string.h>

char * code = "\x48\x31\xc0\xb0\x3c\x48\x31\xff\x0f\x05";

int main(){
   printf("len:%d bytes\n", strlen(code));
   int (*foo)() = (int(*)())code;
   foo();
   return 0;
}
