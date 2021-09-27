#include <stdio.h>
#include <setjmp.h>
static jmp_buf env;
void f1(int);
void f2();
int main(int argc, char* argv){
   switch(setjmp(env)){
      case 0:
	printf("Linux is a simple Operating System\n");
	f1(argc);
	printf("Concentrate and confirm your output\n");
	break;
      case 1:
	printf("Learning Linux is fun...\n");
	break;
      case 2:
	printf("Linux is Gr8\n");
	break;
      default:
	printf("Thanks PUCIT\n");
   }
   return 0;
}
void f1(int argc){
   if (argc==1)
	longjmp(env,1);
   f2();
}
void f2(){
   longjmp(env,3);
}
