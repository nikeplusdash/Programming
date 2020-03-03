printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
scanf macro
    local below,back
    mov bx,2
back:
    mov ah,01
    int 21h
    mov ah,0
    cmp al,40h
    jc below
    sub al,7h
below:
    sub al,30h
    push ax

    dec bx
    cmp bx,0
    jnz back

    pop bx
    pop ax
    mov cl,4
    rol ax,cl
    add ax,bx
    push ax
endm
stack segment
    db 100 dup(?)
stack ends
data segment
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