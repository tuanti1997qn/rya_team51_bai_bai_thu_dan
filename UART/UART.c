/*
 * UART.c
 *
 *  Created on: Oct 15, 2017
 *      Author: tuant
 */



#include "UART.h"

#define TIME_WAIT_FOR_CMD       10
#define MAX_BUF_DATA_RECV       50

uint8_t C1101_Buf[MAX_BUF_DATA_RECV];
uint16_t C1101_ReadIdx = 0;
uint16_t C1101_WriteIdx = 0;
uint16_t u16_avail_byte = 0;

void UARTIntHandler(void)
{
    uint32_t ui32Status;
    ui32Status = UARTIntStatus(CC1101_UART_BASE, true); //get interrupt status
    UARTIntClear(CC1101_UART_BASE, ui32Status); //clear the asserted interrupts

    while(UARTCharsAvail(CC1101_UART_BASE)) //loop while there are chars
    {
        if(((C1101_WriteIdx == (MAX_BUF_DATA_RECV -1))&&(C1101_ReadIdx != 0))||
           ((C1101_WriteIdx != (MAX_BUF_DATA_RECV -1))&&((C1101_WriteIdx+1) != C1101_ReadIdx)))
        {
            C1101_Buf[C1101_WriteIdx++] = UARTCharGetNonBlocking(CC1101_UART_BASE);
            u16_avail_byte++;
            C1101_WriteIdx %= MAX_BUF_DATA_RECV;
        }
    }
}

uint16_t UART_C1101_QueryData(void){
  return (u16_avail_byte);
}

void UART_C1101_Read(uint8_t * buf, uint16_t len)
{
    uint16_t idx;
    if(UART_C1101_QueryData() >= len){
        for(idx = 0; idx < len; idx++){
            if (C1101_ReadIdx != C1101_WriteIdx)
            {
              *(buf + idx) = C1101_Buf[C1101_ReadIdx++];
              if (u16_avail_byte)
              {
                u16_avail_byte--;
              }
            }
            if(C1101_ReadIdx >= MAX_BUF_DATA_RECV){
                C1101_ReadIdx = 0;
            }
        }
    }
}

void CC1101_Init(void){
    //Init UART for CC1101
    SysCtlPeripheralEnable(CC1101_UART);
    SysCtlPeripheralEnable(CC1101_UART_GPIO);

    GPIOPinConfigure(CC1101_UART_RX);
    GPIOPinConfigure(CC1101_UART_TX);
    GPIOPinTypeUART(CC1101_GPIO_BASE, CC1101_GPIO_PIN);

    UARTConfigSetExpClk(CC1101_UART_BASE, SysCtlClockGet(), CC1101_Baudrate, CC1101_UART_Config);

    UARTIntRegister(CC1101_UART_BASE, &UARTIntHandler);
    UARTIntEnable(CC1101_UART_BASE, CC1101_UART_INT_Config); //only enable RX and TX interrupts
    IntEnable(CC1101_UART_INT); //enable the UART interrupt
    IntMasterEnable(); //enable processor interrupts
}

void UART_C1101_Write(uint8_t* c_Buff, uint16_t ui16_len)
{
    uint16_t ui16_idx;
    for(ui16_idx = 0; ui16_idx < ui16_len; ui16_idx++)
    {
        UARTCharPut(CC1101_UART_BASE, (char)c_Buff[ui16_idx]);
    }
}

void UART_C1101_WriteCMD(uint8_t* c_Buff)
{
    while(*c_Buff != 0x00)
    {
        UARTCharPut(CC1101_UART_BASE, (char)(*c_Buff++));
    }
}
