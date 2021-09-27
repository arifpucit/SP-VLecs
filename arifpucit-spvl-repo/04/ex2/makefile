#this is a comment
myexe : mysub.o prog1.o myadd.o  mydiv.o mymul.o
	gcc  prog1.o myadd.o mysub.o mydiv.o mymul.o -o myexe
myadd.o: myadd.c
	gcc -c myadd.c 
mysub.o: mysub.c
	gcc -c mysub.c 
mydiv.o: mydiv.c
	gcc -c mydiv.c
mymul.o: mymul.c
	gcc -c mymul.c
prog1.o: prog1.c mymath.h
	gcc -c -I.  prog1.c 
