/******************************************************************************
 *
 * www.payitforward.edu.vn
 *
 *****************************************************************************/

/*
 * UART.h
 *
 *  Created on: Oct 4, 2017
 *      Author: minht57
 *      Editor: Thai - PIF.MTU - RYA2017
 */

#ifndef UART_UART_H_
#define UART_UART_H_

#include "../include.h"

//#define DEBUG

#ifdef DEBUG

#define CC1101_UART               SYSCTL_PERIPH_UART0
#define CC1101_UART_GPIO          SYSCTL_PERIPH_GPIOA
#define CC1101_UART_RX            GPIO_PA0_U0RX
#define CC1101_UART_TX            GPIO_PA1_U0TX
#define CC1101_GPIO_BASE          GPIO_PORTA_BASE
#define CC1101_GPIO_PIN           (GPIO_PIN_0 | GPIO_PIN_1)
#define CC1101_UART_BASE          UART0_BASE
#define CC1101_Baudrate           9600
#define CC1101_UART_Config        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)
#define CC1101_UART_INT           INT_UART0
#define CC1101_UART_INT_Config    (UART_INT_RX | UART_INT_RT)

#else
//            |   TIVA C   |        |  MODULE CC1101 |
//            |         3v3|------->|VCC             |
//            |         GND|------->|GND             |
//            |         PB0|------->|TXD             |
//            |         PB1|------->|RXD             |

#define CC1101_UART               SYSCTL_PERIPH_UART1
#define CC1101_UART_GPIO          SYSCTL_PERIPH_GPIOB
#define CC1101_UART_RX            GPIO_PB0_U1RX
#define CC1101_UART_TX            GPIO_PB1_U1TX
#define CC1101_GPIO_BASE          GPIO_PORTB_BASE
#define CC1101_GPIO_PIN           (GPIO_PIN_0 | GPIO_PIN_1)
#define CC1101_UART_BASE          UART1_BASE
#define CC1101_Baudrate           9600
#define CC1101_UART_Config        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)
#define CC1101_UART_INT           INT_UART1
#define CC1101_UART_INT_Config    (UART_INT_RX | UART_INT_RT)

#endif

void UART_C1101_Read(uint8_t * buf, uint16_t len);
void CC1101_Init(void);
void UART_C1101_Write(uint8_t* c_Buff, uint16_t ui16_len);
void UART_C1101_WriteCMD(uint8_t* c_Buff);

#endif /* UART_UART_H_ */

/******************************************************************************
 * END OF UART.h
 *****************************************************************************/
