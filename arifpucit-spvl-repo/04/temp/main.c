/*
*  Video Lecture: 04
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#include <stdio.h>
#include <main.h>
#include <compute.h>
#include <input.h>
int main()
{
   double x, y;
   printf("The program takes x and y from stdin and displays x^y.\n");
   x = input(PROMPT1);
   y = input(PROMPT2);
   printf("x^y is: %6.0f\n", mypower(x,y));
   return 0;
}
