printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
data segment
    a db 5,4,9,3,9,8,6,99,56
    n db $-a
    key db ?,"$"
    ans db "SMALLEST NUMBER: $"
data ends
code segment
    assume ds:data,cs:code
start:
    mov ax,data
    mov ds,ax
    lea si,a
    mov al,a
    mov cl,n
    dec cl
    dec si
back:
    inc si
    cmp [si],al
    jc smol
    loop back
    add al,30h
    mov key,al
    printf ans
    printf key
    jmp exit
smol:
    mov al,[si]
    jmp back
exit:
    mov ah,4ch
    int 21h
code ends
end start