/*
*  Video Lecture: 36
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  unixdomain_udpreceiver.c: Creates a UNIX domain datagram socket
*  and then reads a string from this socket
*  written by the the sender program
*  and displays it on stdout
*  compile: gcc unixdomain_udpreceiver.c
*  usage: ./a.out
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
   int sockfd;
   struct sockaddr_un server_addr;
//STEP-I *****Remove any old sockets and create  socket
   unlink("./socketfile");
   sockfd = socket (AF_UNIX, SOCK_DGRAM, 0);
//STEP-II ****Populate socket's DS for the sockaddr_un type by giving the filename and then bind server_sockfd with this file
   server_addr.sun_family = AF_UNIX;
   strcpy(server_addr.sun_path, "./socketfile");
   bind(sockfd, (struct sockaddr*)&server_addr, sizeof server_addr);
//*** STEP-III: Use recvfrom to receive msg from client
   char buff[100];
   int addr_len = sizeof server_addr;
   recvfrom(sockfd,buff,sizeof buff,0,(struct sockaddr*)&server_addr, &addr_len);
   printf("Welcome Mr. %s \n", buff); 
//*** STEP-IV
      close(sockfd);
   return 0;
 }
