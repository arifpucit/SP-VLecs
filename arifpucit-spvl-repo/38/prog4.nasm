#  Video Lecture: 38
#  Programmer: Arif Butt
#  Course: System Programming with Linux
#  prog4.nasm: Assembly program that calls C Lib func puts and exit
#  Assemble: nasm -felf64 prog4.nasm
#  Link:     gcc -no-pie prog4.o
#  usage:    ./a.out

global main
extern puts
extern exit

SECTION .text
   main:
      mov rdi, msg
      call puts
      ret

      mov rdi, 0
      call exit
      ret

SECTION .data
   msg: db "Learning is fun with Arif"
