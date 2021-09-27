#this is a comment
myexe : input.o main.o compute.o
	gcc  input.o main.o compute.o -o myexe
main.o: main.c main.h compute.h input.h
	gcc -c main.c -I. 
compute.o: compute.c compute.h
	gcc -c compute.c 
input.o: input.c input.h
	gcc -c input.c -I.
