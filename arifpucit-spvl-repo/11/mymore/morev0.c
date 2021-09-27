/* 
* Video Lecture 11
* morev0.c: get single file name via command line argument and print entire contents of file and exits
*/
#include <stdio.h>
#include <stdlib.h>
#define LINELEN 512
void do_more(FILE *);
int main(int argc , char *argv[]){
   if (argc == 1){
       printf("This is the help page\n");
       exit (0);
   }
   FILE * fp;
   fp = fopen(argv[1] , "r");
   if(fp == NULL){
       perror("Can't open file");
       exit(1);
   }
   do_more(fp);
   fclose(fp); 
   return 0;
}

void do_more(FILE *fp){
   char buffer[LINELEN];
   while(fgets(buffer, LINELEN, fp)){
      fputs(buffer, stdout);
   }
}
