/*
*  Video Lecture: 34
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  getportnumber.c: Receives a service name via command line argument
*  Use getservbyname(), which returns a servent structure from
*  the file /etc/services that matches the service name using protocol
*  and finally displays the port number corresponding to service name
*  compile: gcc getportnumber.c
*  usage: ./a.out <hostname>
*/
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
int main (int argc, char **argv){
   if (argc != 2){
      printf("Must enter a service name (e.g, echo, ftp)...\n");
        exit (1);
    }
    struct servent *pse; //pointer to service information entry
    pse = getservbyname(argv[1], '\0');
    printf("Service Name: %s\n", pse->s_name);
    printf("Port number: %d\n", ntohs(pse->s_port));
    return 0;
}
