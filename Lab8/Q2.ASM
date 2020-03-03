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
adj macro
    local down
    cmp al,9
    jc down
    add al,7h
    down:
    add al,30h
endm
stack segment
    db 100 dup(?)
stack ends
data segment
    q db 10,13,"Enter a hex number: $"
    a db 10,13,"Sum: "
    carry db 0
    inp dw ?
    newline db "H",10,13,"$"
data ends
code segment
assume cs:code,ds:data,ss:stack
main:
    mov ax,data
    mov ds,ax
    mov ax,stack
    mov ss,ax

    printf q
    scanf
    printf q
    scanf

    pop ax
    pop bx
    add al,bl
    adc carry,30h
    mov ah,0
    mov cl,4
    ror ax,cl
    ror ah,cl
    adj
    xchg ah,al
    adj
    xchg ah,al
    mov inp,ax
    
    printf a
    mov ah,4ch
    int 21h
code ends
end main