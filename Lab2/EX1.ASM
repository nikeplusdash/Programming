DATA SEGMENT
        ARRAY1 DB 0A0H,0B1H,0C2H,0D3H,0E4H
        ARRAY2 DB 5 DUP(?)
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
PROG:
        MOV AX,DATA
        MOV DS,AX
        LEA SI,ARRAY1   ;SOURCE POINTER
        LEA DI,ARRAY2   ;DESTINATION POINTER

        MOV AL,[SI]
        MOV [DI],AL
        INC SI
        INC DI

        MOV AL,[SI]
        MOV [DI],AL
        INC SI
        INC DI

        MOV AL,[SI]
        MOV [DI],AL
        INC SI
        INC DI

        MOV AL,[SI]
        MOV [DI],AL
        INC SI
        INC DI

        MOV AL,[SI]
        MOV [DI],AL

        MOV AH,4CH
        INT 21H
CODE ENDS
END PROG
