#ifndef UART_H_config
#define UART_H_config
#include <avr/io.h>
#define  Baudrate    1200
#define F_CPU 8000000UL
#define  UBRRVALUE   ((F_CPU)/(Baudrate*16UL)-1UL)

#endif