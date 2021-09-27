#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
//how to display text
printf("\e[7m This is in reverse video\n");
printf("\033[m This is in normal video\n");
printf("\033[1m This is bold \033[m \n");
printf("\033[4m This is underlined \033[m \n");

//Changing foreground and background colours
printf("\033[35m \033[40m This is in magenta colour with black back ground \033[39m \033[49m\n");

//cursor movement
printf("\033[10G This will start from column 10 \n");
printf("\033[10;20H This will appear in row 10 column 20 \n");
printf("\033[5B This is going to appear 5 lines below \n");

getchar();
//clearing parts of the screen
printf("\033[2J");
return 0;
}
