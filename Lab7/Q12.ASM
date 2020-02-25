printf macro msg
    mov dx,offset msg
    mov ah,09
    int 21h
endm
data segment
    a dw 666,999,66,99,69,996
    n db ($-a)/2
    key dw 99
    succ db "KEY IS FOUND AT $"
    res db "  POSITION",13,10,"$"
    fail db "KEY NOT FOUND",13,10,"$"
data ends
code segment
    assume ds:data,cs:code
start:
    mov ax,data
    mov ds,ax
    lea si,a
    mov ax,key
    mov dx,0
    mov ch,0
    mov cl,n
    sub si,2
back:
    add si,2
    cmp [si],ax
    loopnz back
    jcxz nope
    printf succ
    mov dl,n
    sub dl,cl
    add dl,'0'
    mov res,dl
    printf res
    jmp exit
nope:
    printf fail
exit:
    mov ah,4ch
    int 21h
code ends
end start