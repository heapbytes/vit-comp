
Prof. Anant N Kaulage VIT Pune



Write Macro:
------------------------------------------------------------
%macro println 2
	mov rax,01h
	mov rdi,01h
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro





Procedures: To Accept Numbers from User/To Display on COnsole
-------------------------------------------------------------
acceptNo:

	mov rax,00h
	mov rdi,00h
	mov rsi,accept
	mov rdx,03h
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







