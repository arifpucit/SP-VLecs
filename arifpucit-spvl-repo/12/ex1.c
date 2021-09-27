#include <stdlib.h>
#include <unistd.h>

int main()
{
   char buff[256];
   read (0, buff, 255);
   write(1, buff, 255); 
   return 0;

}
