global main

SECTION .data
msg: db "Welcome to System Programming with Arif Butt...", 0Ah, 0h
len_msg: equ $ - msg

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
	syscall         ; exit(49)

