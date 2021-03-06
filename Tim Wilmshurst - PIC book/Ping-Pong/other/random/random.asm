                list	p=16F84

pcl             equ     2
status          equ     3
porta           equ     5
trisa           equ     5
portb           equ     6
trisb           equ     6

pointer         equ     10
delcntr1        equ     11
delcntr2        equ     12


                org     0

start           bsf     status, 5
                movlw   B'00011000'
                movwf   trisa
                movlw   0
                movwf   trisb
                bcf     status, 5

                movlw   0
                movwf   porta
                movwf   pointer
loop            movf    pointer, 0
                call    table
                movwf   portb
                call    delay
                incf    pointer, 1
                btfsc   pointer, 3
                clrf    pointer
                goto    loop

delay           movlw   D'100'
                movwf   delcntr2
outer           movlw   D'200'
                movwf   delcntr1
inner           nop
                nop
                decfsz  delcntr1, 1
                goto    inner
                decfsz  delcntr2, 1
                goto    outer
                return

table           addwf   pcl
                retlw   23
                retlw   3f
                retlw   47
                retlw   7f
                retlw   0a2
                retlw   1f
                retlw   03
                retlw   67
                end