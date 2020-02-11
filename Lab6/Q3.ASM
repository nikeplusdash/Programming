.MODEL
.DATA
    NUM DB 5,6
    LCM DW ?
.STACK
.CODE
CALC PROC
    BACK: 
        PUSH AX
        DIV BL
        CMP AH,0
        JZ DOWN
        POP AX
        ADC AL,NUM
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

    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN