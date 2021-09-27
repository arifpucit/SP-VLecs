/*
*  Video Lecture: 34
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  unixdomain_tcpechoserver.c: Server programs runs on local machine
*  binds itself to socketfile in pwd, 
*  waits for client connection
*  receives a string from client
*  and will send it back to client
*  compile: gcc unixdomain_tcpechoserver.c
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
   int server_sockfd;
   int client_sockfd;
   struct sockaddr_un server_addr;
   struct sockaddr_un client_addr;
//STEP-I *****Remove any old sockets and create an unnamed socket for the server
   unlink("./socketfile");
   server_sockfd = socket (AF_UNIX, SOCK_STREAM, 0);
//STEP-II ****Populate socket's DS for the sockaddr_un type by giving the filename and then bind server_sockfd with this file
   server_addr.sun_family = AF_UNIX;
   strncpy(server_addr.sun_path, "./socketfile", sizeof(server_addr.sun_path)-1);
   bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof server_addr);
//STEP-III ***Create a connection queue and wait for clients
   listen(server_sockfd, 5); 
   while(1){
      fprintf(stderr,"\nServer waiting for client connection...");
//STEP-IV **** Accept a connection, blocks until connection from client is established
//        **** will return a brand new descriptor to use for this single connection
      int client_len = sizeof client_addr;
      client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_addr, &(client_len));
      fprintf(stderr, "\n********* CLIENT CONNECTION ESTABLISHED ********");
      
//STEP-V ***** Read from sockfd and write back
      char buf[100];
      int rv;
      while (rv = read(client_sockfd, buf, sizeof buf))
        write(client_sockfd, buf, rv);
      close(client_sockfd);
      fprintf(stderr, "\n********* CLIENT CONNECTION TERMINATED ********");
      }
   return 0;
 }
