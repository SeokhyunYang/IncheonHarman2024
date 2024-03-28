/*
 * test04-Timer.c
 *
 * Created: 2024-03-28 오전 10:57:18
 * Author : SYSTEM-00
 */ 
#include "myHeader.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// volatile - ISR 내에서 사용할 변수를 컴파일러가 최적화하는 것을 금지
volatile unsigned long cnt = 0, tcnt = 0;
volatile unsigned long state = 0, timer = 0, reset = 0, tset = 0;

int main(void)
{
	SegPort(&PORTC, &PORTD, &DDRC, &DDRD);
	
	DDRA = 0x01;	// LED1을 출력으로 설정
	DDRE = 0x00;	// 0000 0000, PE4~6=0
	
	EIMSK = 0x70;	// 0111 0000 - INT4~6 인터럽트 활성화
	EICRB =	0x2A;	// 0010 1010  - INT4~6 하강 에지에서 인터럽트 발생
	
	TIMSK |= 0x01;	// 0000 0001b - TOIE0 (Timer 0 TCNT Overflow Interrupt Enable)	
	TCCR0 = 0x04;	// 0000 0100b - 분주비(Pre-Scaler) 64
	
	SREG |= 0x80;	// Status Register - 인터럽트 허용
	sei();			// set interrupt - 인터럽트 시작
	
	int timeset = 0;
	int cntstop = 1000000;
	
	while (1)
    {
		if(cnt >= 0x10000) cnt = 0;
		SegDisp(4, cnt);
		
		
		// 타이머 설정 모드
		switch(timer)
		{
			case 0: break;
			case 1:
			{
				tset = 0;
				while(timer == 1)
				{
					timeset = tset * 600;
					for(int i = 0; i < 25; i++)
					{
						SegDisp(4, timeset);
						_delay_ms(1000);
						SegDisp(3, timeset);
						_delay_ms(1000);
					}
				}
				
				
				state = 0, timer = 0, cnt = 0;
				
				break;
			}
			default: break;
		}
		
		
		// reset을 누르면 초기화
		if(reset)
		{
			state = 0, timer = 0, reset = 0;
			cnt = 0, tcnt = 0;
		}
    }
}


ISR(TIMER0_OVF_vect)
{
	if(state)	// sw1로 start/stop
	{
		tcnt++;
		if(tcnt >= 1000)	// 1KHz/1000 : 1cnt/sec
		{
			cnt++; tcnt = 0;
		}
	}
}

ISR(INT4_vect)	// INT4 인터럽트 처리 루틴 : sw1
{
	state = (state + 1) % 2;
	tset++;
}
ISR(INT5_vect)	// INT5 인터럽트 처리 루틴 : sw2
{
	timer++;
}
ISR(INT6_vect)	// INT6 인터럽트 처리 루틴 : sw3
{
	reset++;
}
