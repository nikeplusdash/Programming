printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
scanf macro
    lea dx,buffer
    mov ah,0ah
    int 21h
    push ax
endm
stack segment
    db 10 dup(?)
stack ends
data segment
    buffer db 2
    len db ?
    s db 2 dup(?)
    q db 10,13,"Enter a hex number: $"
    a db 10,13,"Decimal: "
    inp db 0,0,0
    newline db 10,13,"$"
data ends
code segment
assume cs:code,ds:data,ss:stack
CONVERT PROC   
    MOV CL,0AH
    DIV CL
    ADD AH,30H
    MOV [DI],AH
    MOV AH,0
    DEC DI
    RET
CONVERT ENDP
main:
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax
    lea di,inp+2

    printf q
    scanf

    mov ah,0
    pop ax
    MOV CX,3
    
    BACK:
        PUSH CX
        CALL CONVERT
        POP CX
    LOOP BACK
    
    printf a
    mov ah,4ch
    int 21h
code ends
end main