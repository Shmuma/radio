#include <pingpong.h>

#use fast_io(a)
#use fast_io(b)


static int8 out_of_game;
static int8 dir_left;
static int8 field;


/* led pins */


void init_device ();
void update_field ();


void main()
{
    init_device ();

    while (1) {
        if (out_of_game) {
            if (!input (BTN_A) || !input (BTN_B)) {
                dir_left = field = 1;
                out_of_game = 0;
                output_low (LED_OUT);
            }
        }
        else
            update_field ();
        delay_ms (300);
    }
}



void init_device ()
{
    set_tris_a (0x18);          /* 0b11000 */
    set_tris_b (0);

    output_b (0);
    output_a (0);

    out_of_game = 1;

    output_high (LED_OUT);
}


void score (int8 pin)
{
    output_high (LED_B);
    dir_left = field = 1;
}


void update_field ()
{
    output_a (0);
    output_b (field);
    if (dir_left)
        field <<= 1;
    else
        field >>= 1;
    if (!field) {
        dir_left = !dir_left;
        if (dir_left) {
            field = 1;
            if (input (BTN_A))
                score (LED_A);
        }
        else {
            field = 0x80;
            if (input (BTN_B))
                score (LED_B);
        }
    }
    else {
        if (!input (BTN_A))
            score (LED_B);
        if (!input (BTN_B))
            score (LED_A);
    }
}
