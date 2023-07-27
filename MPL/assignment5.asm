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

%macro convert 2
cmp byte[%1],9
jbe label%2
add byte[%1],7h
label%2:
add byte[%1],30H
%endmacro

section .data
;array dq 0000000000000001h,0000000000000002h,1111111111110110h,111111111101101h,0000000000000003h
array: dq -23,38,-66,89,-90
pos_count:db 0
neg_count:db 0
count:db 5
str1:db 'Count of positive numbers are: ',0xA
len1 equ $-str1
str2:db 'Count of negative numbers are: ',0xA
len2 equ $-str2

section .text
global _start
_start:
mov rsi,array
l1:
mov rax,qword[rsi]
BT rax,63 ;use to check the 63rd bit of content of rax
jc negative

inc byte[pos_count]
add rsi,8 ;move to next element
dec byte[count]
JNZ l1
jmp HtoA

negative:
inc byte[neg_count]
add rsi,8
dec byte[count]
JNZ l1

HtoA:
convert pos_count,2
convert neg_count,3
 
print str1,len1
print pos_count,1
print str2,len2
print neg_count,1

mov rax,60
mov rdi,1
syscall





