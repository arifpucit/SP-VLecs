//f2w.c
//Program receives a file name as cmd line parameters, opens it in append mode and get a name from user and write it in file 
//                     f2w  friends.txt
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
	if(argc !=2){
		printf("Invalid number of arguments. Please enter file name to display its contents...\n");
		exit(1);
	}
	
	FILE* fp = fopen(argv[1], "a");
	if (fp == NULL){perror("fopen failed"); exit(1);}
	char name[100];
        printf("Enter your friend's name: ");
        scanf("%[^\n]s", name);
	fputs(name, fp);
        fputc('\n',fp);	
	fclose(fp);
	printf("\nDone bye bye...\n");
	return 0;
}
