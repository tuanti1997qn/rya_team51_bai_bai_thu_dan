/*
 * thu_dan.c
 *
 *  Created on: Oct 15, 2017
 *      Author: tuant
 */
#include "quet_led.h"

// hieu ung 1 sang/tat toan bo
void hieu_ung_1(char status,char min_tang ,char max_tang, int32_t _delay)
{
    static char tang;
    for(tang = min_tang; tang <= max_tang ; tang++)
    {
    int row=0;
    choose_layer(tang);
    for(row=0 ; row<8 ; row++)
    {
        int column=0;
        for(column=0 ; column<8 ; column++)
        {
            bit_shift(status);
        }
    }
    write_pin(PORT_control,LATCH_PIN,0);
    delay();
    write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai // latchs
    delay();
//    SysCtlDelay(SysCtlClockGet()/10);
    SysCtlDelay(_delay);
    }
}


// hieu ung 2 sang xen ke
void hieu_ung_2(char min_tang ,char max_tang, int32_t _delay)
{
    int8_t tang;
    for (tang = min_tang; tang<= max_tang; tang++)
    {
    int row=0;
    choose_layer(tang);
    for(row=0 ; row<8 ; row++)
    {
        int column=0;
        for(column=0 ; column<8 ; column++)
        {
            static int a;
            if (a)
            {
                a=0;
            }
            else
            {
                a=1;
            }
            bit_shift(a);
        }
    }
    write_pin(PORT_control,LATCH_PIN,0);
    delay();
    write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai // latchs
    delay();
//    SysCtlDelay(SysCtlClockGet()/10);
    SysCtlDelay(_delay);
    }

    for (tang = min_tang; tang<= max_tang; tang++)
    {
    int row=0;
    choose_layer(tang);
    for(row=0 ; row<8 ; row++)
    {
        int column=0;
        for(column=0 ; column<8 ; column++)
        {
            static int a =1 ;
            if (a)
            {
                a=0;
            }
            else
            {
                a=1;
            }
            bit_shift(a);
        }
    }
    write_pin(PORT_control,LATCH_PIN,0);
    delay();
    write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai // latchs
    delay();
//    SysCtlDelay(SysCtlClockGet()/10);
    SysCtlDelay(_delay);
    }
}
