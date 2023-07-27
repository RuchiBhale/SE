section .data
arr: db 01h, 1Fh, 1Ah, 12h, 04h
str1: db "The array is: ",0xA
len1 equ $-str1
str2: db "Largest no in the array is: ",0xA
len2 equ $-str2
cnt: db 2h

section .bss
ans resb 2
count resb 1

section .text
global _start
_start:

mov rax,01
mov rdi,01
mov rsi,str1
mov rdx,len1
syscall

mov r8,arr
mov al,byte[r8]
mov byte[count],4h
inc r8

label1:
mov bl,byte[r8]
cmp bl,al	;performs subtraction and changes flag value 
JA l2           ;jump if above i.e if bl>al
JMP l3          ;unconditional jump

l2:		
mov al,bl	;move bl into the accumalator 
l3:
inc r8		
dec byte[count]	
JNZ label1	

mov r8,ans
mov byte[cnt], 2
up:
rol al,4
mov bl,al
and bl,0Fh

cmp bl,09H
JBE l1
add bl,07H
l1:
add bl,30H
mov byte[r8],bl
inc r8
dec byte[cnt]
JNZ up

mov rax,01
mov rdi,01
mov rsi,str2
mov rdx,len2
syscall

mov rax,01
mov rdi,01
mov rsi,ans
mov rdx,2
syscall

mov rax,60
mov rdi,00
syscall


