section .bss
array resb 100

section .data
str1:db "Enter 5 numbers: ",0xA
len1 equ $-str1

str2:db "The 5 numbers are: ",0xA
len2 equ $-str2

cnt1:db 05
cnt2:db 05


section .text
global _start
_start:
mov rax,01
mov rdi,01
mov rsi,str1
mov rdx, len1
syscall

mov r8,array

L1:
mov rax,00
mov rdi,00
mov rsi,r8
mov rdx,17
syscall

add r8,17
dec byte[cnt1]
JNZ L1

mov rax,01
mov rdi, 01
mov rsi,str2
mov rdx,len2
syscall

mov r8,array
L2:
mov rax,01
mov rdi,01
mov rsi,r8
mov rdx,17
syscall

add r8,17
dec byte[cnt2]
JNZ L2

mov rax,60
mov rdi,00
syscall



