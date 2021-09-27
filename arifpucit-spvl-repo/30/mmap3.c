/*
*  Video Lecture: 30
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Program mmaps an entire file in its address space
*  and then write some more txt in that memory mapped region
*  usage: ./mmap3
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
   int fd = open("f1.txt", O_RDWR);
// Stretch the file size to the new size
   lseek(fd, 100, SEEK_END); 
    write(fd, "", 1);

//get attributes of the file
   struct stat sbuff;
   fstat(fd, &sbuff);
   int fsize = sbuff.st_size;

//memory map the file
   char* filedata = mmap(NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
   printf("Data of f1.txt that is mapped in memory is:\n%s", filedata);

//now write something in the file (remember the cfo is at the end)
   char *newdata = "This is GR8\n";
   strcat(filedata, newdata);
   printf("New data in the memory mapped region is:\n%s", filedata);
//sync it
   msync(filedata, fsize, MS_SYNC);
   munmap(filedata, fsize);
   close(fd);
   return 0;
}
