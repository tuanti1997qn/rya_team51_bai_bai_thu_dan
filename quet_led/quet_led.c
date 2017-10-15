/*
 * quetled.c
 *
 *  Created on: Oct 4, 2017
 *      Author: tuant
 */

#include "quet_led.h"

char led_cube[8][8][8];// x: row, y: column, z: layer
char a[3];
//-----------------------------------------------------------------------------------------------------------------------
//* extern function

void quet()
{
    static char tang = 0;
    layer_shift(tang);
    tang ++ ;
    if(tang == 8)
    {
        tang = 0;
    }
    SysCtlDelay(SysCtlClockGet()/10);
//    SysCtlDelay(20000);
}

void set_led_cube(char x, char y, char z)
{
    led_cube[x][y][z] = 1;
}

void clear_led_cube(char x, char y, char z)
{
    led_cube[x][y][z] = 0;
}

char get_led_cube(char x, char y, char z)
{
    return led_cube[x][y][z];
}

//-----------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------
//* static function
void bit_shift(char bit)        //dich 1 bit vao 74HC595
{
    if(bit)
    {
        write_pin(PORT_control,DATA_PIN,DATA_PIN);
    }
    else
    {
        write_pin(PORT_control,DATA_PIN,0);
    }
    write_pin(PORT_control,CLK_PIN,0);
    delay();
    write_pin(PORT_control,CLK_PIN,CLK_PIN);        //xem lai
    delay();
}

//void bit_shift(char bit)        //dich 1 bit vao 74HC595
//{
//    if(bit)
//    {
//        write_pin(PORT_control,DATA_PIN,0);
//    }
//    else
//    {
//        write_pin(PORT_control,DATA_PIN,DATA_PIN);
//    }
//    write_pin(PORT_control,CLK_PIN,0);
//    delay();
//    write_pin(PORT_control,CLK_PIN,CLK_PIN);        //xem lai
//    delay();
//}

void column_shift(char layer, char row)     // xem lai ve con dich  // dich 1 cot
{
    int column=0;
    for(column=0 ; column<8 ; column++)
    {
//        bit_shift(led_cube[column][row][layer]);
        static int a =1;
        if (a)
        {
            a=0;
        }
        else
        {
            a=1;
        }
//        bit_shift(a);
        bit_shift(1);
    }

}


//void column_shift(char layer, char row)     // xem lai ve con dich  // dich 1 cot
//{
//    int column=0;
//    for(column=0 ; column<8 ; column++)
//    {
//        bit_shift(0);
//    }
//}

//void column_shift1(char layer, char row)     // xem lai ve con dich  // dich 1 cot
//{
//    int column=0;
//    for(column=0 ; column<4 ; column++)
//    {
//        bit_shift(1);
//    }
//}

void layer_shift(char layer)            // dich 1 cot
{
    int row=0;
    choose_layer(layer);
//    choose_layer(6);
    for(row=0 ; row<8 ; row++)
    {
        column_shift(layer, row);
    }
    write_pin(PORT_control,LATCH_PIN,0);
    delay();
    write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai // latchs
    delay();

//    for(row=0 ; row<8 ; row++)
//    {
//        column_shift(layer, row);
//    }
//    write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai // latchs
//   delay();
//   write_pin(PORT_control,LATCH_PIN,0);
//   delay();
//   SysCtlDelay(SysCtlClockGet());
}

void choose_layer(char layer)
{
    char pin[8]= {GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7};
    uint32_t port[8]= { GPIO_PORTD_BASE,GPIO_PORTD_BASE,GPIO_PORTD_BASE,GPIO_PORTD_BASE, GPIO_PORTC_BASE, GPIO_PORTC_BASE, GPIO_PORTC_BASE , GPIO_PORTC_BASE};
    write_pin(GPIO_PORTD_BASE , Layer_pinD , 0);
    write_pin(GPIO_PORTC_BASE , Layer_pinC , 0);
//    write_pin(GPIO_PORTC_BASE , Layer_pinC , GPIO_PIN_1);
    write_pin(port[layer] , Layer_pin , pin[layer]);
}

//void choose_layer(char layer)
//{
//    write_pin(GPIO_PORTD_BASE , Layer_pin , GPIO_PIN_0);
//}
/*void choose_layer(char layer)
{
    write_pin(Layer_port_control, GPIO_PIN_4, GPIO_PIN_3);
}*/
//-----------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------
//hardware function
void write_pin(unsigned int port, unsigned int pin, unsigned int data)
{
    GPIOPinWrite(port, pin, data);
}
void delay()
{
    SysCtlDelay(10);
}
//-----------------------------------------------------------------------------------------------------------------------

