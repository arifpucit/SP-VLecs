//cpxters.c
//Program receives two file names as cmd line parameters and copies contents of src file to dest file byte by byte
//                     cpxters  password.txt   backuppassword.txt
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char * argv[])
{
	if(argc !=3){
		printf("Invalid number of arguments. Please enter src and dest file names...\n");
		exit(1);
	}
	
	FILE* in = fopen(argv[1], "r");
	if (in == NULL){printf("Error in opening file\n"); exit(1);}
	FILE *out = fopen(argv[2], "w");
	if (out == NULL){printf("Error in creating file\n"); exit(1);}
		
	char ch;
	while((ch = fgetc(in))!= EOF){
		fputc(ch, out);
	}
	fclose(in);
	fclose(out);
	printf("Copy done...\n");
	return 0;
}
