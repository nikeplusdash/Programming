.MODEL
.DATA
    NUM DW 50,25,80,90
    GCD DW ?,?,?
.STACK
.CODE
CALC PROC
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
        MOV GCD,BX
    RET
CALC ENDP
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AX,NUM
    MOV BX,NUM+2
    CALL CALC
    MOV AX,GCD
    MOV BX,NUM+4
    CALL CALC 
    MOV AX,GCD
    MOV BX,NUM+6
    CALL CALC
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN