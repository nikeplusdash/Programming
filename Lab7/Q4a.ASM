printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
data segment
    a db 5,4,9,3
    ; 9,8,6,1,3,5,2,4,8,7
    n db $-a
    msg1 db "BEFORE SORTING: $"
    msg2 db 10,13,"AFTER SORTING: $"
    msg3 db 10,13,"DURING SORTING: $"
    space db " $"
data ends
stack segment
    dw 100 dup(?)
stack ends
code segment
    assume ds:data,cs:code,ss:stack
selectionsort proc

ret
selectionsort endp
printarray proc
    mov ch,0
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
    printf msg1
    call printarray
    call selectionsort
    printf msg2
    call printarray
    mov ah,4ch
    int 21h
code ends
end main