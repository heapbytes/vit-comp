%macro println 2
	mov rax,01h
	mov rdi,01h
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro




section .data
array db 12h,40h,80h,9Ah,0FFh

msg0 db 10,'Array Elements Are :: '
len0 equ $-msg0


msg1 db 10,'Positive no Count :: '
len1 equ $-msg1

msg2 db 10,'Negative no Count :: '
len2 equ $-msg2

msg3 db '   '
len3 equ $-msg3


section .bss
positive resb 1
negative resb 1
display resb 2

section .text
	global _start

_start:

	mov cl,05h
	mov rsi,array
	mov bh,00h	;positive
	mov bl,00h	;negative

chkNext:
	mov al,[rsi]
	shl al,01h
	jnc posi
	
	inc bl
	jmp skip	
posi:
	inc bh
skip:
	inc rsi
	dec cl
	jnz chkNext

	mov [positive],bh
	mov [negative],bl

	println msg0,len0

	mov cl,05h
	mov rsi,array

dispNext:
	mov bl,[rsi]

	push rcx
	push rsi

	call displayNo

	println msg3,len3
	
	pop rsi
	pop rcx

	inc rsi
	dec cl
	jnz dispNext	

















	println msg1,len1
	mov bl,[positive]
	call displayNo

	println msg2,len2
	mov bl,[negative]
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







