//countalphabets.c
//Get file name from user via cmd line, open file for reading using ifstream. Count the number of lower case, upper case alphabets, and also digits, spaces and punctuations.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
	char * filename = argv[1];
	FILE* fp = fopen(filename, "r");
	if (fp == NULL){printf("Error in opening file\n"); exit(1);}
	char ch;
	int lc=0, uc=0, dig=0, ws=0, pun=0, other=0;
	while ((ch=fgetc(fp)) != EOF)
	{
		//myFile.get(ch);
		if(islower(ch)) lc++;
		else if (isupper(ch)) uc++;
		else if (isdigit(ch)) dig++;
		else if (isspace(ch)) ws++;
		else if (ispunct(ch)) pun++;
		else other++;
	}
	printf("Upper Case      :%d\n",uc);
	printf("Lower Case      :%d\n",lc);
	printf("Digits          :%d\n",dig);
	printf("Punctuations    :%d\n",pun);
	printf("Other Characters:%d\n",other);
	return 0;
}
