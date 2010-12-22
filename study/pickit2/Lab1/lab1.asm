#include <p16F887.inc>

        __CONFIG        _CONFIG1, _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_OFF & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
        __CONFIG        _CONFIG2, _WRT_OFF & _BOR21V
        
        org     0

Start:
        bsf     STATUS, RP0
        bcf     TRISD,  0
        bcf     TRISD,  3
        bcf     STATUS, RP0
        bsf     PORTD,  0
        bsf     PORTD,  3
        goto    $
        end