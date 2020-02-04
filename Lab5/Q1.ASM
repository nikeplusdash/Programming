TITLE HEX TO DECIMAL
.MODEL SMALL
.DATA
    BCD DW 1234H
    HEX DW ?
.CODE
CONVERT PROC        ;PROCEDURE TO GET 10*X+Y
    MOV AH,0        ;AX = 00yz
    MOV DH,0F0H
    MOV DL,0FH
    AND DL,AL       ;DL = 000z
    AND AL,DH       ;AX = 00y0
    MOV CL,4        
    SHR AL,CL       ;AX = 000y
    MOV BL,0AH
    MUL BL          ;AX <- AL * BL
    ADD AL,DL       ;AX <- AX + DL
    RET
CONVERT ENDP
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    MOV AX,BCD      ;AX = 1234H
    MOV CL,8           
    SHR AX,CL       ;AX = 0012H
    CALL CONVERT
    MOV BL,100
    MUL BL
    MOV HEX,AX
    MOV AX,BCD      ;AX = 1234H
    AND AX,00FFH    ;AX = 0034H
    CALL CONVERT
    ADD HEX,AX

    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN