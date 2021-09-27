/*
*  Video Lecture: 38
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  stackoverflow.c: A sample code showing stack based buffer overflow
*  Receives a string via command line argument, pass it to a function
*  which creates a fixed size buffer and copy that string in that buffer
*  using strcpy() function, and then display the string on stdout
*  Finally the control returns to the main function
*  compile: gcc stackoverflow.c
*  usage: ./a.out AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void f1(char* str){
	char buff[10];
 	strcpy(buff, str);
	printf("The command line received is: %s \n", buff);
}

int main(int argc, char * argv[]){
	if(argc > 1)
		f1(argv[1]);
	else
		printf("No command line received.\n");
   exit(0);
}
