#include <stdio.h>
#include <setjmp.h>
static jmp_buf envbuf;
void func();
int main(){
   int i;
   printf("This is main()\n");
   if ((i = setjmp(envbuf)) == 0){
      printf("Value of i = %d\n", i);
      func();
      printf("This will not be printed");
   }
   printf("This is main() again.\n");
   printf("Value of i = %d\n", i);
   return 0;
}
void func(){
   printf("This is fun()\n");
   longjmp(envbuf,52);
}
