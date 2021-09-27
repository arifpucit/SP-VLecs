//repositioning.c
//Program just explains the behavior of repositioning functions: fseek, ftell, fgetpos, fsetpos, and rewind
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* fp = fopen("seekfile.txt", "r+");
	if (fp == NULL){printf("Error in opening file\n"); exit(1);}
	char ch;
	while((ch = fgetc(fp))!= EOF){
		fputc(ch, stdout);
	}
	printf("\n Now lets seek...");
	printf("\n Current positing of file offset: %d\n",ftell(fp));
        rewind(fp);
	printf("\n After rewind the offset is:  %d",ftell(fp));
	printf("\n Lets move the offset to position 5");
        int posn=5;
        fsetpos(fp,(fpos_t*)&posn);
        printf("\nNow lets write lower character 'z' at current offset, i.e. at the location of character 'f'");
        fputc('z',fp);
        printf("\nNow lets display the file again from current file offset:");
	while((ch = fgetc(fp))!= EOF){
		fputc(ch, stdout);
	}
        printf("\nNow lets rewind and display again:");
        rewind(fp);
	while((ch = fgetc(fp))!= EOF){
		fputc(ch, stdout);
	}
        printf("\nNow lets seek past the end of file, and write some characters over there:");
        fseek(fp,5,SEEK_END);
        fputs("Arif Butt",fp);
        printf("\nNow lets rewind and display again:");
        rewind(fp);
	while((ch = fgetc(fp))!= EOF){
		fputc(ch, stdout);
	}
        printf("\n");
        return 0;
}
