#include <p18f2550.inc>

;;;         CONFIG        _CONFIG1, _DEBUG_OFF & _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_ON & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
;;;         CONFIG        _CONFIG2, _WRT_OFF & _BOR21V

;;; 12 MH external clock
CONFIG  FOSC=HS, CPUDIV=OSC1_PLL2, PLLDIV=3
CONFIG  DEBUG=OFF

cblock  20
        Delay1
        Delay2
endc

;;; LCD demo board constants
RS      equ     RB0
RW      equ     RB1
E       equ     RB2
DB0     equ     RA0
DB1     equ     RA1
DB2     equ     RA2
DB3     equ     RA3
DB4     equ     RA4
DB5     equ     RA5
DB6     equ     RB3             ; Note that B reg used
DB7     equ     RB4
        
        org     0

        ;; output on A and B ports
        clrf    TRISA
        clrf    TRISB

        clrf    PORTA
        clrf    PORTB
        
        ;; R/W -> 0, RS -> 0
;;;     bcf     PORTB, RS
;;;     bcf     PORTB, RW

;;;     bcf     PORTB, E

        ;; wait for init completed
        movlw   1
        call    Delay250us

        call    InitLCD
        
ClearLoop:
        call    ClearLCD
        goto    ClearLoop

;;; Delay subroutine. W reg must hold amount of 250 us delays
Delay250us:
        movwf   Delay2
Delay250Loop:
        decfsz  Delay1, f
        goto    Delay250Loop
        decfsz  Delay2, f
        goto    Delay250Loop
        return

;;; W reg must hold amount of 2 us delays
Delay2us:
        movwf   Delay1
Delay2Loop:     
        decfsz  Delay1, f
        goto    Delay2Loop
        return

;;; Routine clears LCD
ClearLCD:
        movlw   1
        call    Delay250us
        
        ;; RS = 0, RW = 0, DB1-DB7 = 0, DB0 = 1
        bsf     PORTB, E

        movlw   1
        call    Delay250us
        
        bsf     PORTA, DB0

        movlw   1
        call    Delay250us

        bcf     PORTB, E
        
        movlw   1
        call    Delay250us

        clrf    PORTA

        movlw   1
        call    Delay250us
        return


;;; Initializes LCD function
InitLCD:
        movf    PORTB, WREG
        bsf     WREG, E
        movwf   PORTB
        movlw   1
        call    Delay250us

        bsf     PORTA, DB5      ; function set
        bsf     PORTA, DB4      ; 8-bit mode
        bsf     PORTA, DB3      ; 2 line display
        bcf     PORTA, DB2      ; 8x5 dot matrix

        movlw   1
        call    Delay250us

        bcf     PORTB, E

        movlw   1
        call    Delay250us

        clrf    PORTA
        clrf    PORTB

        movlw   1
        call    Delay250us
        
        return
        end
        