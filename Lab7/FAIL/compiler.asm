.MODEL
.STACK
.DATA
    masm db "MASM.EXE ",10 dup(?)
    link db "LINK.EXE ",10 dup(?)
    td db "TD.EXE ",10 dup(?)
    debug db ?
.CODE
MAIN PROC
    mov ax,@data
    mov ds,ax
    mov ah,0
    mov al,es:[80h]
    lea si,es:[80h]
    ;moving no. of arguments
    mov ax,es:[si]
    mov debug,al
    ;moving arguments
    mov dh,0
    mov dl,masm
    mov ah,62h
    int 21h
    mov ax,4b00h
    int 21h
    mov ah,4ch
    ;terminate
    mov ah,4ch
    int 21h
MAIN ENDP
END MAIN