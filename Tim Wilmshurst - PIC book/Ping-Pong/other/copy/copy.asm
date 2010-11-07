		list p=16F84A

status	equ	3
porta	equ	5
trisa	equ 5
portb	equ	6
trisb	equ 6

		org 0

start	bsf		status, 5
		movlw	B'00011000'
		movwf	trisa
		movlw	0
		movwf	trisb
		bcf		status, 5
		clrf	porta
loop	movf	porta, 0
		movwf	portb
		goto	loop
		halt
		end