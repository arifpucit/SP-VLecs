/*
*  Video Lecture: 34
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  unixdomain_tcpechoclient.c: Client programs connects
*  to a unix domain socket file created by server program
*  with the name of socketfile in pwd
*  sends a string and receives the same string
*  and display it on stdout
*  compile: gcc unixdomain_tcpechoclient.c
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
   int sockfd;
   sockfd = socket (AF_UNIX, SOCK_STREAM, 0);
//STEP-II *** Populate socket's DS for sockaddr_un type by giving the file name as agreed with the server
   struct sockaddr_un address;
   address.sun_family = AF_UNIX;
   strncpy(address.sun_path, "./socketfile", sizeof(address.sun_path)-1);
//STEP-III **** Connect this socket to the server's socket
   int rv = connect(sockfd, (struct sockaddr*)& address, sizeof address);
   if(rv == -1){ fprintf(stderr, "Error in connection."); exit(1);}
//*** STEP-IV:  Client reads string from stdin and send it to server
//***           then read string returned by server and display on stdout
   char buff1[128],buff2[128] ;
   while(1){
      int n = read(0, buff1, sizeof buff1);   
      buff1[n] = '\0';
      write(sockfd, buff1, strlen(buff1));
      n = read(sockfd, buff2, strlen(buff1));
      buff2[n] = '\0';
      write(1, buff2, n);
   }
//*** STEP-V:  Close socket
   close(sockfd);
   exit(0);
}
