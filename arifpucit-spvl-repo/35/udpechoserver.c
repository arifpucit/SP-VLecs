/*
*  Video Lecture: 35
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  udpechoserver.c: Server programs runs on ubuntu server
*  binds itself to ip 192.168.100.20 and port 54154, 
*  waits for client connections
*  receives a string from client 
*  and send it back to client
*  compile: gcc udpechoserver.c
*  usage: ./a.out
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
int main(){ 
//*** STEP-I:  Create UDP socket for the server
   int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
//*** STEP-II: Populate Socket's DS for local IP and Port, and
//***          then bind the server_sockfd with this address
   struct sockaddr_in server_addr;
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(54154);
   server_addr.sin_addr.s_addr = INADDR_ANY;
//   inet_aton("192.168.100.20", &server_addr.sin_addr);
   memset(&(server_addr.sin_zero), '\0', sizeof server_addr.sin_zero);
   bind(sockfd, (struct sockaddr*)&server_addr, sizeof server_addr);
//*** STEP-III: Use recvfrom to receive msg from client and 
//***           use sendto to send back same msg to client
   while(1){
      char buff[100];
      int addr_len = sizeof server_addr;
      recvfrom(sockfd,buff,sizeof buff,0,(struct sockaddr*)&server_addr, &addr_len);
      sendto(sockfd,buff,sizeof buff,0,(struct sockaddr*)&server_addr,sizeof server_addr);
   }
//*** STEP-IV
   close(sockfd);  
   return 0;
 }
