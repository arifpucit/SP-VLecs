/*
*  Video Lecture: 34
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  gethostname.c: Receives a FQDN via command line argument
*  Use gethostbyname(), which either reads the /etc/hosts file or
*  queries the name server in the network for resolving the name
*  and finally displays the ip address corresponding to the FQDN
*  compile: gcc gethostname.c
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
        printf("You must enter the name of host whose IP U wanna find\n");
        exit (1);
    }
    struct hostent *phe; //pointer to host information entry
    phe=gethostbyname(argv[1]);
    printf("Host Name: %s\n", phe->h_name);
    printf("IP Address: %s\n", inet_ntoa(*((struct in_addr *)phe->h_addr)));
    return 0;
} 
