/*
*  Video Lecture: 35
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  udpchoclient_unconnected.c: Client program connects to the echo
*  service running on the ubuntuserver having ip 192.168.100.20
*  at port 7, sends a string and receives the same string
*  and display it on stdout
*  compile: gcc udpechoclient_unconnected.c
*  usage: ./a.out <ip> 7
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
  if(argc != 3){printf("Must enter IP and port of echo server\n"); exit(1);}

//*** STEP-I:  Create a socket
   int sockfd = socket (PF_INET, SOCK_DGRAM, 0);

//*** STEP-II: Populate Socket's DS for remote IP and Port, and
//***          let the local IP and Port be selected by the OS itself
   struct sockaddr_in dest_addr;
   dest_addr.sin_family = AF_INET;    
   dest_addr.sin_port = htons(atoi(argv[2]));
   inet_aton(argv[1], &dest_addr.sin_addr);
   memset(&(dest_addr.sin_zero), '\0', sizeof dest_addr.sin_zero); 

//*** STEP-III: Get a string from user and use sendto() to send that string
//***           to echo server and then read a message from server and display on stdout  
   char buff1[128],buff2[128] ;
   while(1){
      int n = read(0, buff1, sizeof buff1);   
      buff1[n] = '\0';
      sendto(sockfd, buff1, sizeof buff1, 0, (struct sockaddr*) &dest_addr, sizeof dest_addr);
int addr_len = sizeof dest_addr;
      recvfrom(sockfd, buff2, sizeof buff2, 0, (struct sockaddr*) &dest_addr, &addr_len);
      buff2[n] = '\0';
      write(1, buff2, n);
   }

//*** STEP-IV:  Close socket
   close(sockfd);
   exit(0);
}
