#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if(argc != 2 ) {
		printf("Must give the env variable name\n");
		exit(0);
	}
	char* ptr = getenv(argv[1]); // get env var address on stack
//	ptr += (strlen(argv[0]) - strlen(argv[2]))*2; // adjust for program name 
	printf("Addr of %s is: %p\n", argv[1], ptr);
}

