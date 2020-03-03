.MODEL 
.STACK 100h

.CODE

main PROC

    ; http://www.ctyme.com/intr/rb-2791.htm
    mov ah, 40h         ; DOS 2+ - WRITE - WRITE TO FILE OR DEVICE
    mov bx, 1           ; File handle = STDOUT
    xor ch, ch
    mov cl, ds:[0080h]  ; CX: number of bytes to write
    mov dx, 81h         ; DS:DX -> data to write (command line)
    int 21h             ; Call MSDOS

    ; http://www.ctyme.com/intr/rb-2974.htm
    mov ax, 4C00h       ; AH=4Ch, AL=00h -> exit (0)
    int 21h             ; Call MSDOS
main ENDP

END main