.MODEL
.DATA
    NUM DW 50,25,80,90
    GCD DW ?
.STACK
CALC MACRO
    LOCAL UP,DOWN,BACK,BIGBZ
    UP:
        CMP AX,BX
        JZ DOWN
        JC BIGBZ
    BIGBZ:
        XCHG AX,BX
        JMP BACK
    BACK:
        MOV DX,0
        DIV BX
        CMP DX,0
        JZ DOWN
        MOV AX,DX
        JMP UP
    DOWN:
        PUSH BX
ENDM
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    MOV AX,NUM
    MOV BX,NUM+2
    CALC
    MOV AX,NUM+4
    MOV BX,NUM+2
    CALC 
    POP AX
    POP BX
    CALC
    POP GCD
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN