#include "UART.h"
void vUARTinit(void ){
	//baud rate setting 
	UBRRH=UBRRVALUE>>8;
	UBRRL=UBRRVALUE;
	//mode of uart
	//UCSRC&=~(1<<UMSEL);
	//data 8 
	UCSRC|=(1<<URSEL);
	UCSRC&=~(1<<UCSZ2);
	UCSRC|=(1<<UCSZ1);
	UCSRC|=(1<<UCSZ0);
	//double speed
	// the reciver and the transmitter
    UCSRB|=(1<<RXEN);
    UCSRB|=(1<<TXEN);
}
void vUART_Transmit(u8 data){
	//when the udr flaf set to ben enable transmit the data to udr
	while (!(UCSRA&(1<<UDRE)));
	UDR=data;
}
u8 ucUART_recieve(void){
	//when uth flag of the recieve data is one there is no unread data in the udr
		while (!(UCSRA&(1<<RXC)));
		return UDR;
}
void vUART_message(u8* z){
	while (*z!=0)
	{
		vUART_Transmit(*z);
		z++;
	}
}
