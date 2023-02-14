%macro println 2 ; macro of write system call code
mov rax,01 ;write System call number
mov rdi,01 ; File discriptor OR Device ID
mov rsi,%1 ; first parameter
mov rdx,%2 ; second parameter
syscall
%endmacro

section .data
    msg db "Success "
    len equ $-msg
    
    msg1 db "Is Always"
    len1 equ $-msg1
    
section .bss
section .text
global _start ; Assembling purpose
    _start:   ; linking purpose
    
      println msg,len ; macro call which will display Success"
        
      mov rsi,msg1
      mov rdx,len1
      call print ; procedure call will display "Is Always"
        
    mov rax,60
    syscall
    
    print:         ; Procedure code
        mov rax,01
        mov rdi,01
        syscall
        
        