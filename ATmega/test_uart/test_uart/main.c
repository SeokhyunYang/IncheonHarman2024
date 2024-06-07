/*
 * test_uart.c
 *
 * Created: 2024-06-07 오전 10:36:35
 * Author : user
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

void initUART0()	// 9600N81
{
	// UBRRn = UBRRnH + UBRRnL (n : UART0 or UART1)
	UBRR0H = 0;
	UBRR0L = 207;	// Baud rate : 9600
	
	UCSR0A |= (1 << U2X0);					// UCSRnA : U2Xn = 1 2배속 설정 (0000 0010)
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);	// RX/TX Enable (1100 0000)
	UCSR0C |= 0x06;							// Data bit : 8 (0000 0110)
	// 초기 설정 = 비동기 UART, Stop bit : 1, Parity bit : x
}

void uPutc(char c)
{
	//while(1)
	//{
	//	if( UCSR0A & (1 << UDRE0) == 1 ) break;
	//}
	while( !(UCSR0A & (1 << UDRE0)) ) ; //	Wait until data empty bit '1'
	UDR0 = c;	// Send
}

void uPuts(char *str)
{
	while(*str) uPutc(*str++);
	
	while(1)
	{
		if(*str == 0) break;
		uPutc(*str);
		str++;
	}
}

unsigned char buf[1024];
void bPrint()
{
	uPuts(buf);
}

int main(void)
{
	initUART0();
    char a = '0';
	int i = 0;
	uPuts("안녕하세요..... \r\n");
	
	while (1)
    {
		//uPutc(a++);
		//if(a > '9') a = '0';
		
		sprintf(buf, "ATmega128 터미널 출력 테스트...#%d\r\n", i++); bPrint();
		_delay_ms(1000);
		
    }
}

