#include <setjmp.h>
#include<stdio.h>
#include <stdlib.h>
static jmp_buf env;
static void f2(){
  longjmp(env,2);
}
void f1(int argc){
 if (argc == 1)
   longjmp(env,1);
 f2();
}
int main(int argc , char *argv[]){
 printf("value of argc is: %d\n", argc);
 switch(setjmp(env)){
    case 0:
       printf("calling f1() after initial setjmp()\n");
       f1(argc);
       printf("Hai\n");
       break;
    case 1: 
       printf("we jumped back from f1()\n");
       break;
    case 2:
       printf("we jumped back from f2()\n");
       break;
  }
  exit(EXIT_SUCCESS);
}
