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
        
        org     0

        ;; output on A and B ports
        clrf    TRISA

Loop:   
        ;; calibrate delay loop
        bsf     PORTA, RA0
        movlw   10
        call    Delay2us
        bcf     PORTA, RA0
        movlw   20
        call    Delay2us
        goto    Loop

        ;; Delay subroutine. W reg must hold amount of 250 us delays
Delay250us:
        movwf   Delay2
DelayLoop:
        decfsz  Delay1, f
        goto    DelayLoop
        decfsz  Delay2, f
        goto    DelayLoop
        return

        ;; W reg must hold amount of 2 us delays
Delay2us:
        movwf   Delay1
Delay1Loop:     
        decfsz  Delay1, f
        goto    Delay1Loop
        return
        end

        