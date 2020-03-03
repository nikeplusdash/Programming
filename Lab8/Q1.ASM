printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
scanf macro
    mov ah,01
    int 21h
    mov inp,al
endm
scanfs macro
    mov ah,08
    int 21h
    mov inp,al
endm
data segment
    q db "Enter a character: $"
    a db 10,13,"Input: "
    inp db ?
    newline db 10,13,"$"
data ends
code segment
assume cs:code,ds:data
main:
    mov ax,data
    mov ds,ax
    printf q
    scanfs
    printf a
    printf q
    scanf
    printf a
    mov ah,4ch
    int 21h
code ends
end main