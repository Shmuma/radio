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

        ;; switch ports to digital
        bsf     ADCON1, 0
        bsf     ADCON1, 1
        bsf     ADCON1, 2
        bsf     ADCON1, 3
        
        clrf    PORTA
        clrf    PORTB

        call    InitLCD

        movlw   1
        call    WriteLCD
        
WriteLoop:
        call    WaitForBusyFlag
        movlw   B'00100100'
        call    WriteLCDChar
        goto    WriteLoop

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
        movlw   10
        call    Delay2us
        movlw   30
        call    WriteLCD
        movlw   10
        call    Delay2us
        movlw   30
        call    WriteLCD
        movlw   10
        call    Delay2us
        movlw   30
        call    WriteLCD
        call    WaitForBusyFlag
        movlw   B'111000'         ; 8 bit, 2 line, 8x5 dots
        call    WriteLCD
        return

WaitForBusyFlag:
        bsf     TRISA, DB7      ; switch it to input
        bcf     PORTB, RS
        bsf     PORTB, RW

WaitLoop:
        nop
        bsf     PORTB, E
        nop

        bcf     PORTB, E

        btfsc   PORTB, DB7
        goto    WaitLoop

        bcf     TRISA, DB7
        bcf     PORTB, RW
        return

;;; write byte from WReg to LCD
WriteLCD:
        bcf     PORTB, RS
        bcf     PORTB, RW
        nop
        nop
        nop
        nop
        bsf     PORTB, E
        movwf   PORTA
        bcf     PORTB, DB6
        bcf     PORTB, DB7
        btfsc   WREG, 6
        bsf     PORTB, DB6
        btfsc   WREG, 7
        bsf     PORTB, DB7
        nop
        nop
        nop
        nop
        bcf     PORTB, E
        return

WriteLCDChar:
        bsf     PORTB, RS
        bcf     PORTB, RW
        nop
        nop
        nop
        nop
        bsf     PORTB, E
        movwf   PORTA
        bcf     PORTB, DB6
        bcf     PORTB, DB7
        btfsc   WREG, 6
        bsf     PORTB, DB6
        btfsc   WREG, 7
        bsf     PORTB, DB7
        nop
        nop
        nop
        nop
        bcf     PORTB, E
        bcf     PORTB, RS
        return
        end
