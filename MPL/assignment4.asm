%macro print 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro read 2
mov rax,00
mov rdi,00
mov rsi,%1
mov rdx,%2
syscall
%endmacro
section .data
str2: db"The addition is",0xA
num1: dq 5H
num2: dq 2H

section .bss
ans resb 16
cnt resb 2
choice resb 1

section .text
global _start
_start:

read choice,1
cmp byte[choice],31H
JE addition
cmp byte[choice],32H
JE subtract
cmp byte[choice],33H
JE multiply
cmp byte[choice],34H
JE divide

addition:
mov rax,qword[num1]
mov rbx,qword[num2]
ADD rax,rbx
call HtoA
JMP exit

subtract:
mov rax,qword[num1]
mov rbx,qword[num2]
SUB rax,rbx
call HtoA
JMP exit

multiply:
xor rdx,rdx
mov rax,qword[num1]
mov rbx,qword[num2]
MUL rbx
push rax

mov rax,rdx
call HtoA
pop rax
call HtoA
JMP exit

divide:
xor rdx,rdx
mov rax,qword[num1]
mov ebx,dword[num2]
Div ebx
push rax

mov rax,rdx
call HtoA
pop rax
call HtoA
JMP exit

exit:
mov rax,60
mov rdi,00
syscall

HtoA:
mov r8,ans
mov byte[cnt], 16
up:
rol rax,4
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
print ans,16
RET
