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
    mov es,ax
    mov ah,0
    mov al,es:[80h]
    lea si,es:[80h]
    ;moving no. of arguments
    mov al,[si]
    mov debug,al
    ;moving arguments
    mov ah,4ch
    int 21h
MAIN ENDP
END MAIN