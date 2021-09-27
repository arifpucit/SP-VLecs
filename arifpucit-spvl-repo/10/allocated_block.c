/*
*  Video Lecture: 10
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
   int size = atoi(argv[1]);
   char* a = (char*) malloc(size);
   char* b = (char*) malloc(size);
   char* c = (char*) malloc(size);
   char* d = (char*) malloc(size);
   printf("a = %p\nb = %p\nc = %p\nd = %p\n", a,b,c,d);
}
