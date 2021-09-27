/*
*  Video Lecture: 13
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv){
  printf("Number of args: %d\n", argc);
  for(int i = 0; i < argc; i++)
     printf("argv[%d]: %s\n", i, argv[i]);
  return 0;
}
