all: myexe
CC=gcc
CFLAGS= -std=c11 -O0 -Wall -g
INCLUDES=.
LIBS = -lc
OBJS= myadd.o prog1.o mysub.o mydiv.o mymul.o ./d1/mymod.o
INSTDIR = /usr/bin

myexe: $(OBJS)
	$(CC) -o myexe $(OBJS)  $(LIBS)
myadd.o: myadd.c 
	$(CC) -c myadd.c  $(CFLAGS)
mysub.o: mysub.c
	$(CC) -c mysub.c  $(CFLAGS)
mydiv.o: mydiv.c
	$(CC) -c mydiv.c  $(CFLAGS)
mymul.o: mymul.c
	$(CC) -c mymul.c  $(CFLAGS)
prog1.o: prog1.c mymath.h ./d1/mymod.h
	$(CC) -c prog1.c -I$(INCLUDES) $(CFLAGS)

include: ./d1/makefile

clean:
	-@rm -f $(OBJS)

install: myexe
	@if [ -d $(INSTDIR) ]; \
	then \
		cp myexe $(INSTDIR) && \
		chmod a+x $(INSTDIR)/myexe && \
		chmod og-w $(INSTDIR)/myexe && \
		echo "myexe installed successfully in $(INSTDIR)"; \
	fi

uninstall:
	@rm -f $(INSTDIR)/myexe
	@echo "myexe successfully un-installed from $(INSTDIR)"
