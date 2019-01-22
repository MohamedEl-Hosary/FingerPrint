#ifndef UART_H
#define UART_H
#include "UART-CONFIG.h"
#include "STD_Types_H.h"
void vUART_Transmit(u8);
u8 ucUART_recieve(void);
void vUARTinit(void );
void vUART_message(u8*);
#endif
