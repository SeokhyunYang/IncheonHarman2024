/*
 * test02.c
 *
 * Created: 2024-03-22 오전 9:10:13
 * Author : SYSTEM-00
 */ 

#define F_CPU 16000000L					//Board CLK 정보(16MHz)
#include <avr/io.h>
#include <avr/delay.h>


int main(void)
{
	uint8_t numbers[] = {
		0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67
	};
	int i, j;
	DDRD = 0xFF;						//세그먼트 제어 핀 8개를 출력으로 설정
	DDRC = 0x0F;						//자릿수 선택 핀 4개를 출력으로 설정

	void display_digit(int position, int number){
		PORTC |= 0x0F;
		PORTC &= ~(1 << (position - 1));
		
		PORTD = numbers[number];
	}

	while(1){
		display_digit(1, 1);
		_delay_ms(5);
		display_digit(2, 2);
		_delay_ms(5);
		display_digit(3, 3);
		_delay_ms(5);
		display_digit(4, 4);
		_delay_ms(5);
		
	}
}