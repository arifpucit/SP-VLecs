//f1w.c
//Program receives a file name as cmd line parameters, opens it and append a name of friend in it character by character
//                     f1w  friend.txt
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
	if(argc !=2){
		printf("Invalid number of arguments...\n");
		exit(1);
	}
	
	FILE* fp = fopen(argv[1], "a");
	if (fp == NULL){printf("Error in opening file\n"); exit(1);}
	char name[20];
        printf("Enter a name of friend: ");
        fgets(name, 20, stdin);
        int len =  strlen(name);

        name[len-1]='\0';

        int i=0;
           while((name[i])!= '\0')
                  fputc(name[i++],fp);
        fputc('\n',fp);
	fclose(fp);
	printf("\nDone bye bye...\n");
	return 0;
}
