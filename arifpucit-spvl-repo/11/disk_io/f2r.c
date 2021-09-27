/*f2r.c
Program receives a file name as cmd line parameters, opens it and reads and display its contents line by line
                     f2r friends.txt
*/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
	if(argc !=2){
		printf("Invalid number of arguments. Please enter file name to display its contents...\n");
		exit(1);
	}
	
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL){perror("fopen() failed"); exit(1);}
	char buf[512];
	while(fgets(buf,512,fp)!= NULL){
		fputs(buf, stdout);
	}
	fclose(fp);
	return 0;
}
