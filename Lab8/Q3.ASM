printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
conv macro
    local down
    cmp al,40h
    jz down
    sub al,7h
    down:
    sub al,30h
    mov cl,1
    mul cl
    aam
    add ax,3030h
    xchg al,ah
    mov inp,ax
endm
data segment
    q db "Enter a character: $"
    a db 10,13,"Input: "
    inp dw ?
    newline db 10,13,"$"
data ends
code segment
assume cs:code,ds:data
main:
    mov ax,data
    mov ds,ax
    printf q
    mov ah,08
    int 21h
    conv
    printf a
    printf q
    mov ah,01
    int 21h
    conv
    printf a
    mov ah,4ch
    int 21h
code ends
end main