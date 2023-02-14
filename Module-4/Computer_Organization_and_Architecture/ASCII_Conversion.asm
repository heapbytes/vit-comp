%macro println 2
	mov rax,01h
	mov rdi,01h
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro




section .data
msg1 db 10,'Enter key :'
len1 equ $-msg1

msg2 db 10,'Eq Hex :'
len2 equ $-msg2

section .bss
accept resb 2
display resb 2

section .text
	global _start

_start:

	println msg1,len1
	
	mov rax,00h
	mov rdi,00h
	mov rsi,accept
	mov rdx,02h
	syscall

	println msg2,len2

	mov al,[accept]
	and al,0f0h
	mov cl,04h
	shr al,cl

	add al,30h
	mov [display],al

	mov al,[accept]
	and al,0fh
	add al,30h

	cmp al,39h
	jle dontAdd

	add al,07h

dontAdd:


	mov [display+1],al

	println display,02h


	mov rax,60
	syscall











