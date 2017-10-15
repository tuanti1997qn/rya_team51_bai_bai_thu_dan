

/**
 * main.c
 */
#include "include.h"
int main(void)

{
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    Config_LED();
//    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    CC1101_Init();
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    int i = 0;
    int a=0;
/*    while(1)
    {
        UART_C1101_Read(GetData,1);
        TempData = GetData[0];
//      SysCtlDelay(SysCtlClockGet()/30);

        if (GetData[0] =='A')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_1|GPIO_PIN_2);
        }
        if (GetData[0] =='B')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_3|GPIO_PIN_1);
        }
        if (GetData[0] =='C')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_2|GPIO_PIN_3);
        }
        if (GetData[0] =='D')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_2);
        }
        if (GetData[0] =='E')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_1);
        }
        if (GetData[0] =='F')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_2);
        }
        if (GetData[0] =='G')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_3);
        }
        if (GetData[0] =='H')
        {
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
        }
    }*/


//    init_snake();
//    int o=4;
//    set_led_cube(0,0,o);
//    set_led_cube(0,1,o);
//
//    set_led_cube(1,0,o);
//    set_led_cube(0,3,o);
//    set_led_cube(0,4,o);
//    set_led_cube(0,5,o);
//    set_led_cube(0,6,o);
//    set_led_cube(0,7,o);

//    set_led_cube(0,0,2);
//    set_led_cube(0,0,3);
////    set_led_cube(0,0,4);
////    set_led_cube(0,0,5);
//    set_led_cube(0,0,6);
//    set_led_cube(0,0,7);

//    set_led_cube(2,0,0);
//    set_led_cube(1,0,0);
//    set_led_cube(1,0,1);
//    set_led_cube(1,0,2);
//    set_led_cube(1,0,3);
//    set_led_cube(1,0,4);
//    set_led_cube(1,0,5);
//    set_led_cube(1,0,6);

//    set_led_cube(1,6,0);
//    set_led_cube(1,5,0);
//    set_led_cube(1,4,0);
//    set_led_cube(1,3,0);
//    set_led_cube(1,2,0);
//    set_led_cube(1,1,0);
//    set_led_cube(1,7,0);
//    set_led_cube(3,0,0);
//    set_led_cube(1,1,1);
//    set_led_cube(1,1,7);
//    set_led_cube(1,2,1);
//    set_led_cube(3,1,1);
//    int x,z=0;
//    write_pin(GPIO_PORTD_BASE , Layer_pin , 0);
//    write_pin(GPIO_PORTC_BASE , Layer_pin , 0);
//    write_pin(GPIO_PORTD_BASE , Layer_pin , GPIO_PIN_0);
    while(1)
    {
//        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);
//        quet();
        hieu_ung_2(0, 7, SysCtlClockGet()/10);
//        z=0;
//        for(x=0;x<65;x++)
//        {
//            if(z)
//            {
//                write_pin(PORT_control,DATA_PIN,DATA_PIN);
//                z=0;
//            }
//            else
//            {
//                write_pin(PORT_control,DATA_PIN,0);
//                z=DATA_PIN;
//            }
//            write_pin(PORT_control,CLK_PIN,0);
//            SysCtlDelay(10000);
//            write_pin(PORT_control,CLK_PIN,CLK_PIN);        //xem lai
//            SysCtlDelay(10000);
//        }
//        write_pin(PORT_control,LATCH_PIN,0);
//        SysCtlDelay(10000);
//        write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai // latchs
//        SysCtlDelay(10000);
    }
	return 0;
}
