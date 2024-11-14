data segment:
msg1 db 10,13,"enter first number$"
msg2 db 10,13,"enter 2nd number$"
msg3 db 10,13,"enter 3rd num$"
msg4 db 10,13,"average$"
msg5 db 10,13,"$"
msg6 db 10,13,"/$"
data ends
code segment
assume cs:code,ds:data 
start:
mov ax,data 
mov ds,ax
clc
lea dx,msg1 
mov ah,09h 
int 21h
mov ah,01h
int 21h
mov bh,al 
lea dx,msg2 
mov ah,09h
int 21h
mov ah,01h
int 21h
mov bl,al 
lea dx,msg3 
mov ah,09h 
int 21h 
mov ah,01h 
int 21h 
mov cl,al 
mov al,bh
add al,cl
adc al,bl
mov ah,00h 
jc carry
mov dh,03h
div dh
mov ch,ah
jmp last
carry:
mov ah,01h
mov dx,0003h
div dx
mov ch,ah
last:
lea dx,msg4
mov ah,09h
int 21h
mov dl,al
mov ah,02h
int 21h
cmp ch,00h 
jz full
lea dx,msg5
mov ah,09h
int 21h
add ch,30



