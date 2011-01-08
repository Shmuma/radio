#include <p16f887.inc>

        __CONFIG        _CONFIG1, _DEBUG_OFF & _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_ON & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
        __CONFIG        _CONFIG2, _WRT_OFF & _BOR21V


        org     0

        ;; bank 1
        bsf     STATUS, RP0
        bcf     STATUS, RP1

        ;; output on D port
        clrf    TRISD

        ;; timer 0 prescaler 1:256
        movlw   B'00000111'
        movwf   OPTION_REG

        ;; switch to 31 KHz
        bcf     OSCCON, IRCF0
        bcf     OSCCON, IRCF1
        bsf     OSCCON, IRCF2

        ;; bank 0
        bcf     STATUS, RP0

        clrf    PORTD
        decf    PORTD

loop:
        btfss   INTCON, T0IF
        goto    loop
        bcf     INTCON, T0IF
        incf    PORTD
        goto    loop
        end

        