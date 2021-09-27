#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   char buff[256];
   while(1){
   int n = read (0, buff, 255);
   write(1, buff, n); 
   }
   return 0;

}
