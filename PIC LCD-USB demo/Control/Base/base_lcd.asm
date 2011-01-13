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
        clrf    TRISB

        ;; bcf     OSCCON, IRCF0
        ;; bcf     OSCCON, IRCF1
        ;; bcf     OSCCON, IRCF2
        
        ;; Clear screen command
        bsf     PORTA, 0
        ;; E bit
        bsf     PORTB, RB2
Loop:   
        
        bsf     PORTB, RB7
        bcf     PORTB, RB6

;;;         call    DoDelay
        bcf     PORTB, 2
        bcf     PORTB, RB7
        bsf     PORTB, RB6
;;;         call    DoDelay
        goto    Loop

DoDelay:        
        clrf    Delay1
        clrf    Delay2
Delay:
        decfsz  Delay1, f
        goto    Delay
        decfsz  Delay2, f
        goto    Delay
        return
        
        end

        