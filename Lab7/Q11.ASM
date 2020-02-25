printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
data segment
    a db 5,4,9,3,1,9,8,6,10,11
    n db $-a
    key db 9
    succ db "KEY IS FOUND AT $"
    res db "  POSITION",13,10,"$"
    fail db "KEY NOT FOUND",13,10,"$"
data ends
code segment
    assume ds:data,cs:code
start:
    mov ax,data
    mov ds,ax
    lea si,a
    mov al,key
    mov ah,0
    mov dx,0
    mov ch,0
    mov cl,n
    dec si
back:
    inc si
    cmp [si],al
    loopnz back
    jcxz nope
    printf succ
    mov dl,n
    sub dl,cl
    add dl,'0'
    mov res,dl
    printf res
    jmp exit
nope:
    printf fail
exit:
    mov ah,4ch
    int 21h
code ends
end start