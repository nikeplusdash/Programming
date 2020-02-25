printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
data segment
    a db 5,4,9,3,9,8,6,99,56
    n db $-a
    msg1 db 10,13,"BEFORE SORTING: $"
    msg2 db 10,13,"AFTER SORTING: $"
    space db " $"
data ends
stack segment
    dw 100 dup(?)
stack ends
code segment
    assume ds:data,cs:code,ss:stack

printarray proc
    printf msg1
    mov cl,n
    lea si,a
back:
    mov dl,1
    mov al,[si]
    mul dl
    aam
    add ax,3030h
    xchg dx,ax
    mov ah,02
    int 21h
    printf space
    inc si
    loop back
    ret
printarray endp

main proc
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax
    call printarray

    
exit:
    call printarray
    mov ah,4ch
    int 21h
code ends
end main