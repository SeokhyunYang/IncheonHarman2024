/*
 * test03.c
 *
 * Created: 2024-03-27 오후 12:26:06
 * Author : SYSTEM-00
 */ 

#include "myHeader.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// volatile - ISR 내에서 사용할 변수를 컴파일러가 최적화하는 것을 금지
volatile int state = 0;
volatile int timer = 0;
volatile int reset = 0;


int main(void)
{
	DDRD = 0xFF;		// 세그먼트 제어 핀 8개를 출력으로 설정
	DDRC = 0x0F;		// 자릿수 선택 핀 4개를 출력으로 설정
	DDRA = 0x01;		// LED1을 출력으로 설정
	DDRE = 0x00;		// 0000 0000, PE4~6=0

	// Interrupt 사용 : INT4 ~ INT6 (Ext Int)
	//   Pin Assign   : PE4 ~ PE6
	
	// 인터럽트 설정
	EIMSK = 0x70;	// 0111 0000 - INT4~6 인터럽트 활성화
	EICRB =	0x2A;	// 0010 1010  - INT4~6 하강 에지에서 인터럽트 발생
	SREG |= 0x80;	// Status Register - 인터럽트 허용
	sei();			// set interrupt - 인터럽트 시작
	
	int t = 0;
	int tstop = 10000;
    while (1) 
    {
		switch(state)
		{
			case 0:	// counter stop
				break;
			case 1:	// counter start
				t++; break;
			default: break;
		}
		Disp(t);
		
		// 타이머 설정
		switch(timer)
		{
			case 0:
				break;
			case 1:{
				tstop = t;	// 현재 시간으로 타이머 설정
				state = 0;
				timer = 0;				
				t = 0;
				break;
				}
			default: break;
		}
		
		// 설정된 타이머 시간이 되면 LED 점멸
		if (t > tstop)
		{
			PORTA |= 0x01;	// Port A의 0번째 bit를 HIGH(1)로 출력 - LED 켜기
			_delay_ms(500);
		
			PORTA &= ~0X01;	// Port A의 0번째 bit를 LOW(0)로 출력 - LED 끄기
			for(int i = 0; i < 25; i++)	// 타이머가 완료된 시간을 표시
			{
				Disp(t);
				_delay_ms(10);
			}
			t--;
		}
		
		// reset을 누르면 초기화
		if(reset)
		{
			state = 0;
			timer = 0;
			reset = 0;
			tstop = 10000;
			t = 0;
		}
	}
}

ISR(INT4_vect)	// INT4 인터럽트 처리 루틴 : sw1
{
	state = (state + 1) % 2;
}
ISR(INT5_vect)	// INT5 인터럽트 처리 루틴 : sw2
{
	timer++;
}
ISR(INT6_vect)	// INT6 인터럽트 처리 루틴 : sw3
{
	reset++;
}