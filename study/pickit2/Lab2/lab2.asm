#include <p16F887.inc>

        __CONFIG        _CONFIG1, _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_OFF & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
        __CONFIG        _CONFIG2, _WRT_OFF & _BOR21V


cblock  20
        Delay1
        Delay2
endc
        
        org     0

Start:
        bsf     STATUS, RP0
        clrf    TRISD
        bcf     STATUS, RP0
        movlw   B'10101010'
        movwf   PORTD
Loop:
        movlw   B'11111111'
        xorwf   PORTD,  f

        clrf    Delay1
        clrf    Delay2
Delay:
        decfsz  Delay1, f
        goto    Delay
        decfsz  Delay2, f
        goto    Delay
        
        goto    Loop
        end