.MODEL
.DATA
    NUM DB 5,10,20,25
    LCM DW ?,?,?
.STACK
.CODE
CALC PROC
    UP:
        MOV CX,AX
        CMP AL,BL
        JZ BACK
        JC BIGBZ
    BIGBZ:
        MOV CX,BX
        XCHG AX,BX
        JMP BACK
    BACK: 
        PUSH AX
        DIV BL
        CMP AH,0
        JZ DOWN
        POP AX
        ADC AL,CL
        ADC AH,0
        JMP BACK
    DOWN:
        POP LCM
    RET
CALC ENDP
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    MOV AX,0
    MOV AL,NUM
    MOV BL,NUM+1
    
    CALL CALC
    MOV AX,LCM
    MOV BL,NUM+2
    
    CALL CALC
    MOV AX,LCM
    MOV BL,NUM+3
    
    CALL CALC

    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN