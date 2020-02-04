DATA SEGMENT
        ARRAY1 DW 10000,20000,30000,40000,50000
        ARRAY2 DW 5 DUP(?)
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
PROGRAM:
        ;Moving Data to DS
        MOV AX,DATA
        MOV DS,AX

        ;Declaring Source and Destination Pointer
        LEA SI,ARRAY1
        LEA DI,ARRAY2

        ;Moving data
        MOV AX,[SI]
        MOV [DI],AX
        INC SI
        INC SI
        INC DI
        INC DI

        MOV AX,[SI]
        MOV [DI],AX
        INC SI
        INC SI
        INC DI
        INC DI

        MOV AX,[SI]
        MOV [DI],AX
        INC SI
        INC SI
        INC DI
        INC DI

        MOV AX,[SI]
        MOV [DI],AX
        INC SI
        INC SI
        INC DI
        INC DI

        MOV AX,[SI]
        MOV [DI],AX
        INC SI
        INC SI
        INC DI
        INC DI


        ;Ending Program
        MOV AH,4CH
        INT 21H
CODE ENDS
END PROGRAM
