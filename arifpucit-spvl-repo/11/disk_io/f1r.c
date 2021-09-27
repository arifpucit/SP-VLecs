/*f1r.c
Program receives a file name as cmd line parameters, opens it and read character by character and displays on console
                     $./f1r  friends.txt
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

	int ch;
	while((ch = fgetc(fp))!= EOF){
		fputc(ch, stdout);
	}
	fclose(fp);
	return 0;
}
