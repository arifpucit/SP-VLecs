/*
*  Video Lecture: 37
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  tcpechoserver_select.c: Server programs runs on ubuntu server
*  binds itself to ip 192.168.100.20 and port 54154, 
*  waits for client connections
*  do a multiplexing on all descriptors
*  receives a string from client
*  and will send it back to client
*  compile: gcc tcpechoserver_select.c
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
#define BACKLOG 10  //how many pending connections queue  will hold

int tcpechod(int fd);
int main(){
   int server_sockfd;//socket descriptor for connection establishment
   int client_sockfd; //socket descriptor for data transfer
   struct sockaddr_in server_addr;
   struct sockaddr_in client_addr;
//*** STEP-I:  Create master socket for the server
   server_sockfd = socket (AF_INET, SOCK_STREAM, 0);
//*** STEP-II: Populate address structure and bind
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(54154);
   inet_aton("192.168.100.20", &server_addr.sin_addr);
   memset(&(server_addr.sin_zero), '\0', sizeof server_addr.sin_zero);
   bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof server_addr);
//*** STEP-III: Create a connection queue and wait for clients
   listen(server_sockfd, BACKLOG); 


//*** STEP-IV: Create descriptor set and use select to monitor the descriptors
//***           and data 
   fd_set rfds; //data descriptor set
   fd_set afds;//master descriptor list that will contain every new accepted slave socket descriptor
   FD_ZERO(&rfds);//clear all entries from the set rfds
   FD_ZERO(&afds);//clear all entries from the set afds
   FD_SET(server_sockfd, &afds);//add server sockfd to afds
   int fdmax = getdtablesize();
   while(1){
      memcpy(&rfds, &afds, sizeof rfds);
//use select to monitor and select those descriptors in rfds, that are ready
      select(fdmax, &rfds, NULL, NULL, NULL);
//if server_sockfd  is ready accept the new connection
      if(FD_ISSET(server_sockfd, &rfds)){ //returns true if server_sockfd is ready
         int client_len = sizeof(client_addr);
         client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_addr,&client_len);
         FD_SET(client_sockfd, &afds);//for every accepted connection add fd to afds
      }
//run a loop looking for data descriptor to be read by calling the tcpechod()
      int fd;
      for(fd = 0; fd < fdmax; fd++){
         if(fd != server_sockfd && FD_ISSET(fd, &rfds))
         if(tcpechod(fd) == 0){
            close(fd);
            FD_CLR(fd, &afds);//remove fd from the set afds
         }
      }//end of for loop
   }//end of while loop
}
int tcpechod(int fd){
   char buf[100];
   int rv;
   rv = read(fd, buf, sizeof buf);
   write(fd, buf, rv);
   return rv;
}
