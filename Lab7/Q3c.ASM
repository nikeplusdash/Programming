printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
data segment
    a db 5,4,9,3,9,-4,-1,-1,8,6,1,3,5,2,4,8,7
    n db $-a
    msg1 db "BEFORE SORTING: $"
    msg2 db 10,13,"AFTER SORTING: $"
    space db " $"
data ends
stack segment
    dw 100 dup(?)
stack ends
code segment
    assume ds:data,cs:code,ss:stack
bubblesort proc
    mov ch,0
    mov cl,n
    dec cl
loop1:
    mov si,0
    mov bl,cl
loop2:
    mov al,a[si]
    mov ah,a[si+1]
    cmp al,ah
    jl noswap
    mov a[si],ah
    mov a[si+1],al
noswap:
    inc si
    dec bl
    jnz loop2
    loop loop1
    ret
bubblesort endp
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
    call bubblesort
    printf msg2
    call printarray
    mov ah,4ch
    int 21h
code ends
end main