%macro println 2
	mov rax,01h
	mov rdi,01h
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data
msg1 db 10,'Enter 5 digit BCD Number :'
len1 equ $-msg1

msg2 db 10,'Eq Hex is :: '
len2 equ $-msg2


section .bss

display resb 2
number resb 1
hex resb 2
carry resb 1


section .text
	global _start

_start:

	println msg1,len1


	mov rax,00h
	mov rdi,00h
	mov rsi,number
	mov rdx,01h
	syscall

	mov al,[number]
	sub al,30h
	mov ah,00h
	mov bx,2710h

	mul bx
	
	mov [hex],ax

	cmp dx,0000h
	je goAhead
	
	inc byte[carry]

goAhead:

	mov rax,00h
	mov rdi,00h
	mov rsi,number
	mov rdx,01h
	syscall

	mov al,[number]
	sub al,30h
	mov ah,00h
	mov bx,03e8h
	mul bx

	add [hex],ax
	jnc goAhead1

	inc byte[carry]

goAhead1:
	mov rax,00h
	mov rdi,00h
	mov rsi,number
	mov rdx,01h
	syscall

	mov al,[number]
	sub al,30h
	mov ah,00h
	mov bx,0064h
	mul bx

	add [hex],ax
	jnc goAhead2

	inc byte[carry]

goAhead2:
	mov rax,00h
	mov rdi,00h
	mov rsi,number
	mov rdx,01h
	syscall

	mov al,[number]
	sub al,30h
	mov ah,00h
	mov bx,000ah
	mul bx

	add [hex],ax
	jnc goAhead3

	inc byte[carry]

goAhead3:
	mov rax,00h
	mov rdi,00h
	mov rsi,number
	mov rdx,01h
	syscall

	mov al,[number]
	sub al,30h
	mov ah,00h
	add [hex],ax

	jnc goAhead4

	inc byte[carry]

goAhead4:

	println msg2,len2

	cmp byte[carry],00h
	je dispNext

	add byte[carry],30h
	println carry,01h



dispNext:
	mov bl,[hex+1]
	call displayNo
	
	mov bl,[hex]
	call displayNo






	mov rax,60
	syscall

displayNo:

	mov al,bl
	and al,0f0h
	mov cl,04h
	shr al,cl
	add al,30h
	cmp al,39h
	jle dontAdd
	add al,07h

dontAdd:
	mov [display],al

	mov al,bl
	and al,0fh
	add al,30h
	cmp al,39h
	jle dontAddd
	add al,07h

dontAddd:
	mov [display+1],al

	println display,02h

ret







