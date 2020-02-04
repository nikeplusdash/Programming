code segment
assume cs:code

start:

MOV AX,4926H
MOV AH,4CH
INT 21H

code ends
end start
