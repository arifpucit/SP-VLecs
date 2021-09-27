/*
*  Video Lecture: 36
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  unixdomain_udpsender.c: Sends a string to the receiver program
*  via unix domain socket file created by receiver
*  compile: gcc unixdomain_udpsender.c
*  usage: ./a.out
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[]){
//STEP-I **** Create a socket for the client
   int sockfd = socket (AF_UNIX, SOCK_DGRAM, 0);
//STEP-II *** Populate socket's DS for sockaddr_un type by giving the socket file name
   struct sockaddr_un dest_addr;
   dest_addr.sun_family = AF_UNIX;
   strcpy(dest_addr.sun_path, "./socketfile");
//*** STEP-III: Get a string from user and use sendto() to send that string
//***           to the receiver process
   char buff[128];
   fprintf(stderr, "Enter your name to be sent:");
   int n = read(0, buff, sizeof buff);   
   buff[n] = '\0';
   sendto(sockfd,buff, sizeof buff, 0, (struct sockaddr*) &dest_addr, sizeof dest_addr);
//*** STEP-IV:  Close socket
   close(sockfd);
   exit(0);
}
