#  Video Lecture: 38
#  Programmer: Arif Butt
#  Course: System Programming with Linux
#  prog5.nasm: Assembly program making two system calls using syscall
#  The system call # are in file 
#  /usr/include/x86_64-linux-gnu/asm/unistd_64.h
#  Assemble: nasm -felf64 prog5.nasm
#  Link:     gcc prog5.o
#  usage: ./a.out

global main

SECTION .text
   main:
      mov rax,1
      mov rdi,1 
      mov rsi,msg
      mov rdx,len_msg
      syscall         ; write(1, msg, len_msg);

      mov r15, rax
      mov rax,60
      mov rdi,r15
      syscall         ; exit(26)

SECTION .data
   msg: db "Learning is fun with Arif", 0Ah
   len_msg: equ $ - msg
