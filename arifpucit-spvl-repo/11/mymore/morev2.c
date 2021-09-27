/* 
*  Video Lecture 11
*  morev2.c: read and print one page then pause for a few special commands ('q', ' ' , '\n')
 */

#include <stdio.h>
#include <stdlib.h>

#define	PAGELEN	20
#define	LINELEN	512

void do_more(FILE *);
int  get_input();
int main(int argc , char *argv[])
{
   int i=0;
   if (argc == 1){
       printf("This is the help page\n");
       exit (0);
   }
   FILE * fp;
   while(++i < argc){
      fp = fopen(argv[i] , "r");
      if (fp == NULL){
         perror("Can't open file");
         exit (1);
      }
      do_more(fp);
      fclose(fp);
   }  
   return 0;
}

void do_more(FILE *fp)
{
   int num_of_lines = 0;
   int rv;
   char buffer[LINELEN];
   while (fgets(buffer, LINELEN, fp)){
      fputs(buffer, stdout);
      num_of_lines++;
      if (num_of_lines == PAGELEN){
         rv = get_input();		
         if (rv == 0)//user pressed q
            break;//
         else if (rv == 1)//user pressed space bar
            num_of_lines -= PAGELEN;
         else if (rv == 2)//user pressed return/enter
	    num_of_lines -= 1; //show one more line
         else if (rv == 3) //invalid character
            break; 
      }
  }
}

int get_input()
{
   int c;		
     c=getchar();
      if(c == 'q')
	 return 0;
      if ( c == ' ' )			
	 return 1;
      if ( c == '\n' )	
	 return 2;	
      return 3;
   return 0;
}
