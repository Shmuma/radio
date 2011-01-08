#include <p16f887.inc>

        __CONFIG        _CONFIG1, _DEBUG_ON & _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_ON & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
        __CONFIG        _CONFIG2, _WRT_OFF & _BOR21V


        org     0

        banksel TRISD
        clrf    TRISD
        banksel PORTD
        clrf    PORTD
        movlw   b'11111111'
        movwf   PORTD

        banksel TMR0
        clrf    TMR0
        banksel OPTION_REG
        movlw   B'00000111'
        movwf   OPTION_REG
        
loop:
        btfss   INTCON, T0IF
        goto    loop
        bcf     INTCON, T0IF
        incf    PORTD
        goto    loop
        end

        