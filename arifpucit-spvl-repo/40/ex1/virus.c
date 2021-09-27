/*
*  Video Lecture: 40
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  virus.c: A sample code showing stack based buffer overflow
*  Disable ASLR to make it work
*  echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
*  For execution of shellcode inside the stack make the stack executable,
*  disable the caneries
*  compile: gcc -ggdb -fno-stack-protector -z execstack virus.c -o virus
*  usage: ./virus <  <payloadn.txt>
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int getinput(){
    char buf[10];
    int rv = read(0, buf, 1000);
    printf("\nNumber of bytes read are %d\n", rv);
    return 0;
}

int main() {
    getinput();
    return 0;
}
int virus(){
   printf("Let us Hack Planet Earth with Arif Butt.\n");
   exit(0);
}
