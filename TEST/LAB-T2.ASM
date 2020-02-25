printf macro msg
    mov dx,offset msg
    mov ah,09h
    int 21h
endm
data segment
    a db -5,-4,-3,-2,-1,10,20,30,45,10
    n db $-a
    sum dw ?,"$"
    disp db 10,13,"SUM: $"
data ends
code segment
    assume cs:code,ds:data
main proc
    mov ax,data
    mov ds,ax
    mov cl,n
    lea si,a
    sub si,1
back:
    add si,1
    cmp byte ptr [si],0
    jcxz down
    jge sumup
    loop back
sumup:
    mov bl,[si]
    mov ax,sum
    add al,bl
    daa
    adc ah,0
    xchg ah,al
    daa
    xchg al,ah
    mov sum,ax
    dec cx
    jmp back
down:
    printf disp
    mov ah,0
    mov cl,4
    ror ax,cl
    ror ah,cl
    add ax,3030h
    mov sum,ax
    printf sum
    mov ah,4ch
    int 21h
code ends
end main