;  Video Lecture: 39
;  Instructor: Arif Butt
;  Course: System Programming with Linux
;  hackplanetearth2.nasm: Assembly program making exit system call
;  Assemble: nasm -felf64 hackplanetearth2.nasm

global _start

SECTION .text
   _start:
      jmp call_shellcode
   shellcode:
      pop rsi
      xor rax, rax
      mov al, 1
      mov rdi, rax
      mov rdx, rdi
      add rdx, 40
      syscall         ;write(1, len, msg)

      xor rax, rax
      add rax, 60
      xor rdi, rdi
      syscall         ; exit(0)
   call_shellcode:
      call shellcode
      msg: db 'Let us Hack Planet Earth with Arif Butt',0xa
