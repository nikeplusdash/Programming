DATA SEGMENT
    NUM DW 10,5
    GCD DW ?
DATA ENDS
STACK SEGMENT
     DW 100 DUP(?)
    TOS LABEL WORD
STACK ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA,SS:STACK
PROGRAM:
    MOV AX,DATA
    MOV DS,AX
    MOV AX,STACK
    MOV SS,AX
    LEA SP,TOS
    MOV AX,NUM
    MOV BX,NUM+2

    CALL CALC

    MOV AH,4CH
    INT 21H

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
CODE ENDS
END PROGRAM