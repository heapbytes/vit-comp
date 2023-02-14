%macro println 2
	mov rax,01h
	mov rdi,01h
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data
msg1 db 10,'Enter 4 digit Hex ::'
len1 equ $-msg1


msg2 db 10,'Eq BCd :: '
len2 equ $-msg2


section .bss
quo resb 1
accept resb 2
hex resb 2
remd resb 2

section .text
	global _start

_start:

	println msg1,len1

	call acceptNo
	mov [hex+1],bl
	
	call acceptNo
	mov [hex],bl

	println msg2,len2

	mov dx,0000h
	mov ax,[hex]
	mov bx,2710h
	div bx

	mov [remd],dx

	add al,30h
	mov [quo],al
	println quo,01h


	mov dx,0000h
	mov ax,[remd]
	mov bx,03e8h

	div bx
	mov [remd],dx

	add al,30h
	mov [quo],al
	println quo,01h


	mov dx,0000h
	mov ax,[remd]
	mov bx,0064h

	div bx
	mov [remd],dx

	add al,30h
	mov [quo],al
	println quo,01h


	mov dx,0000h
	mov ax,[remd]
	mov bx,000Ah

	div bx
	mov [remd],dx

	add al,30h
	mov [quo],al
	println quo,01h


	mov ax,[remd]
	add al,30h
	mov [quo],al
	println quo,01h


































	mov rax,60
	syscall


acceptNo:

	mov rax,00h
	mov rdi,00h
	mov rsi,accept
	mov rdx,02h
	syscall

	mov al,[accept]
	sub al,30h
	cmp al,09h
	jle dontSub
	sub al,07h

dontSub:	
	mov cl,04h
	shl al,cl
	mov bl,al

	mov al,[accept+1]
	sub al,30h
	cmp al,09h
	jle dontSubb
	sub al,07h

dontSubb:
	or bl,al
ret



















