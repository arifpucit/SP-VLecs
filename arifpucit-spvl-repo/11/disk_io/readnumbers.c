/*readnumbers.c
Program receives a file name as cmd line parameters containing numbers, opens it and reads and display numbers on stdout
                     ./readnumbers numbersComma.txt
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
	if (fp == NULL){printf("Error in opening file\n"); exit(1);}

	int i;
        fscanf(fp, "%d,", &i); 
	while (feof(fp)==0){
		printf("%d ", i);
		fscanf(fp, "%d,", &i);
	}
        fclose(fp);
        
	printf("\n");
	return 0;
}








