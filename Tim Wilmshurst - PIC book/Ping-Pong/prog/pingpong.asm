                list    p=16F84A

status          equ     3
porta           equ     5
trisa           equ     5
portb           equ     6
trisb           equ     6

led_durn        equ     20
delcntr1        equ     10
delcntr2        equ     11
led_posn        equ     12
loop_cntr       equ     13

                org     0
                goto    start

                org     2
start           bsf     status, 5
                movlw   B'00011000'
                movwf   trisa
                movlw   0
                movwf   trisb
                bcf     status, 5

wait            movlw   4
                movwf   porta
                movlw   0
                movwf   portb

                btfss   porta, 4
                goto    wait
                btfss   porta, 3
                goto    wait

wait1           btfss   porta, 4
                goto    r_to_l
                btfss   portb, 4
                goto    r_to_l
                goto    wait1

r_to_l          movlw   0
                movwf   porta
                movlw   80
                movwf   led_posn

rtl_0           movlw   led_durn
                movwf   loop_cntr

                movf    led_posn, w
                movwf   portb


rtl_1           btfss   led_posn, 7
                goto    rtl_2
                btfss   porta, 3
                goto    rt_myscore
                goto    rtlend

rtl_2           btfss   led_posn, 0
                goto    rtl_3
                btfss   porta, 3
                goto    l_to_r
                btfss   porta, 4
                goto    rt_yrscore
                goto    rtlend

rtl_3           btfss   porta, 4
                goto    score_left
                btfss   porta, 3
                goto    rt_myscore

rtlend          call    delay5
                decfsz  loop_cntr
                goto    rtl_1
                bcf     status, 0
                rrf     led_posn, 1
                btfsc   status, 0
                goto    rt_myscore
                goto    rtl_0

rt_myscore      goto    score_right
rt_yrscore      goto    score_left
                        
l_to_r          movlw   0
                movwf   porta
                movlw   1
                movwf   led_posn
ltr_0           movlw   led_durn
                movwf   loop_cntr

ltr_1           movf    led_posn, w
                movwf   portb
                btfss   led_posn, 0
                goto    ltr_2
                        
                btfss   porta, 4
                goto    lft_myscore
                goto    ltrend

ltr_2           btfss   led_posn, 7
                goto    ltr_3
                        
                btfss   porta, 4
                goto    r_to_l
                btfss   porta, 3
                goto    lft_yrscore
                goto    ltrend

ltr_3           btfss   porta, 4
                goto    lft_myscore
                btfss   porta, 3
                goto    lft_yrscore
        
ltrend          call    delay5
                decfsz  loop_cntr
                goto    ltr_1

                bcf     status, 0
                rlf     led_posn, 1
                btfsc   status, 0
                goto    lft_myscore
                goto    ltr_0

lft_myscore     goto    score_left
lft_yrscore     goto    score_right

score_left      movlw   0
                movwf   portb
                bsf     porta, 1
                call    delay500
                bcf     porta, 1
                goto    wait

score_right     movlw   0
                movwf   portb
                bsf     porta, 0
                call    delay500
                bcf     porta, 0
                goto    wait

delay5          movlw   D'200'
                movwf   delcntr1
del1            nop
                nop
                decfsz  delcntr1, 1
                goto    del1
                return  

delay500        movlw   D'100'
                movwf   delcntr2
del2            call    delay5
                decfsz  delcntr2, 1
                goto    del2
                return
                end