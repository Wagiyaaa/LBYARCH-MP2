section .data
var1 dq 0
var2 dq 255

section .text
bits 64
default rel

global imgCvtGrayIntToDouble

imgCvtGrayIntToDouble:
	MOV [var1], RCX
	MOVSD XMM1, [var1]
	MOVSD XMM2, [var2]

	DIVSD XMM1, XMM2
	MOVSD XMM0, XMM1
	ret

