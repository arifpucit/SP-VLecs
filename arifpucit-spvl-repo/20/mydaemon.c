/*
*  Video Lecture: 20
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Writing a daemon process programmatically
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void create_daemon();
int main(){
   create_daemon(); 
   while(1){}
}
void create_daemon(){
//STEP-I: Make the process child of systemd
   pid_t cpid = fork();
   if(cpid > 0)
      exit(0);
//STEP-II: Close all files descriptors less 0,1,2
   struct rlimit r;
   getrlimit(RLIMIT_NOFILE, &r);
   for(int i=3; i<r.rlim_max; i++)
      close(i);
//STEP-III: Only a single instance of a daemon process should run
   int fd = open("f1.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
   if(fd == -1){perror("open");}
   struct flock lock;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	int rv = fcntl(fd, F_SETLK, &lock);	
   if(rv == -1){
      printf("This process is already running\n");
      close(fd);
      exit(1);
	}
	fprintf(stderr,"Daemon has started running with PID: %d\n", getpid());

//STEP-IV: Make std descriptors point to /dev/null
   int fd0 = open("/dev/null", O_RDWR);
   dup2(fd0, 0);
   dup2(fd0, 1);
   dup2(fd0, 2);
   close(fd0);
//STEP-V: Make the daemon session leader
    setsid();
//STEP-VI: Set umask to 0 and its pwd to /
    umask(0);
	chdir("/");
//STEP-VII: Ignore the SIGHUP signal
signal(SIGHUP,SIG_IGN);
}
