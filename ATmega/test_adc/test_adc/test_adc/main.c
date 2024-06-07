/*
 * test_adc.c
 *
 * Created: 2024-05-31 오후 4:17:55
 * Author : user
 */ 

#define F_CPU 16000000L
#include "myHeader.h"
#include <avr/io.h>
#include <util/delay.h>



void ADC_init(unsigned char channel)
{
	ADMUX |= (1 << REFS0); 		// AVCC를 기준 전압으로 선택
	
	ADCSRA |= 0x07;				// 분주비 설정
	ADCSRA |= (1 << ADEN);		// ADC 활성화
	ADCSRA |= (1 << ADFR);		// 프리 러닝 모드

	ADMUX = ((ADMUX & 0xE0) | channel);	// 채널 선택
	ADCSRA |= (1 << ADSC);		// 변환 시작
}

int read_ADC(void)
{
	while(!(ADCSRA & (1 << ADIF)));	// 변환 종료 대기
	
	return ADC;					// 10비트 값을 반환
}

int main(void)
{
	SegPort(&PORTC, &PORTD, &DDRC, &DDRD);	// Segment 포트, 출력핀 지정
	int read;
	
	ADC_init(0);				// AD 변환기 초기화
	
	while(1)
	{
		read = read_ADC();		// 가변저항 값 읽기
				
		SegDisp(4, read);
		
	}

	return 0;
}

