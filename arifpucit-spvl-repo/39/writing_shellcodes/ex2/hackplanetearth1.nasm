;  Video Lecture: 39
;  Instructor: Arif Butt
;  Course: System Programming with Linux
;  hackplanetearth1.nasm: Assembly program making exit system call
;  Assemble: nasm -felf64 hackplanetearth1.nasm

global _start

SECTION .text
   _start:
      mov rax, 1
      mov rdi, 1
      mov rsi, msg   
      mov rdx, len    
      syscall        ;write(1, msg, len)

      mov rax, 60
      mov rdi, 0
      syscall         ; exit(0)
SECTION .data
      msg: db 'Let us Hack Planet Earth with Arif Butt',0xa
	   len: equ $ - msg
