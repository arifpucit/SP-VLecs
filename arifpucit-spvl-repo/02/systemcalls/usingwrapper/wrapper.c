/*
*  Video Lecture: 02
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <unistd.h>
int main(){
   char str[]={"Welcome to System Programming with Arif Butt...\n"};
   int rv = write(1, str, sizeof str); 
   return rv;
}

