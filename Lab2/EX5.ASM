DATA SEGMENT
        A1 DW 49H,46H,4DH,4DH,50H                                                                                                                                                                                                 
	A2 DW 4DH,50H,4FH,46H,53H
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA

PROGRAM:

MOV AX,DATA
MOV DS,AX

LEA SI,A1
LEA DI,A2

MOV AX,[SI]
MOV BX,[DI]
MOV [SI],BX
MOV [DI],AX
INC SI
INC SI
INC DI
INC DI

MOV AX,[SI]
MOV BX,[DI]
MOV [SI],BX
MOV [DI],AX
INC SI
INC SI
INC DI
INC DI

MOV AX,[SI]
MOV BX,[DI]
MOV [SI],BX
MOV [DI],AX
INC SI
INC SI
INC DI
INC DI

MOV AX,[SI]
MOV BX,[DI]
MOV [SI],BX
MOV [DI],AX
INC SI
INC SI
INC DI
INC DI

MOV AX,[SI]
MOV BX,[DI]
MOV [SI],BX
MOV [DI],AX

MOV AH,4CH
INT 21H

CODE ENDS
END PROGRAM
