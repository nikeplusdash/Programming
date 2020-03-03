.MODEL
.STACK
.DATA
    masm db "MASM.EXE ",20 dup(?)
    link db "LINK.EXE ",20 dup(?)
    td db "TD.EXE ",20 dup(?)
    debug db ?
.CODE
MAIN PROC
    mov ax,@data
    mov ds,ax
    mov ah,0
    lea bx,es:[80h]
    mov debug,bl
    mov bx,si
    inc bx
    mov dh,0
    mov dl,masm
    mov ax,4b00h
    int 21h
    mov ah,4ch
    int 21h
MAIN ENDP
END MAIN