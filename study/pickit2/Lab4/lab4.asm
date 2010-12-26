#include <p16F887.inc>

        __CONFIG        _CONFIG1, _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_OFF & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
        __CONFIG        _CONFIG2, _WRT_OFF & _BOR21V
        
        org     0

Start:
        bsf     STATUS, RP0
        movlw   0xFF
        movwf   TRISA
        clrf    TRISD

        ;; configure ADC
        bcf     ADCON1, ADFM    ;lef justified result
        bcf     ADCON1, VCFG1   ;Vss is Vref-
        bcf     ADCON1, VCFG0   ;Vdd is Vref+

        bsf     STATUS, RP1     ;bank 3
        bsf     ANSEL,  0
        
        bcf     STATUS, RP0     ;bank 0
        bcf     STATUS, RP1
        bsf     PORTD,  0
        movlw   0x41
        movwf   ADCON0         ; configure A2D for Fosc/8, Channel 0 (RA0), and turn on the A2D module

Loop:
        bsf     ADCON0, GO_DONE
        btfss   ADCON0, GO_DONE
        goto    $-1
        movf    ADRESH, w
        addlw   1
        movwf   PORTD
        goto    Loop
        end