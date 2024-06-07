/*
 * CFile1.c
 *
 * Created: 2024-03-28 오전 10:45:34
 *  Author: SYSTEM-00
 */ 

#include "myHeader.h"
#include <avr/io.h>
#include <util/delay.h>

uint8_t digit[] = {	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71};
char arr[5]; // Segment를 담을 안전영역
int sm = 4;	// 출력 자리수를 제한할 변수

char *PC = &PORTA, *PD = &PORTB;	// 7-Segment 포트를 지정할 포인터 변수
char *DC = &DDRA,  *DD = &DDRB;		// 7-Segment 출력핀을 지정할 포인터 변수

void SegPort(char *p1, char *p2, char *d1, char *d2)
{
	PC = p1;
	PD = p2;
	DC = d1;
	DD = d2;
	*DC = 0x0F;	// DDRC = 0x0F; 자릿수 선택 핀 4개를 출력으로 설정
	*DD = 0xFF;	// DDRD = 0xFF; 세그먼트 제어 핀 8개를 출력으로 설정
}

// 7-Segment 사용 : 4 Module - A type
//   Pin Assign   : PDx - Segment image, PCx - Module select
void seg(int sel, uint8_t c)
{
	*PC |= 0x0F;
	*PC &= (1 << (3-sel));
	*PD = ~c;		// 숫자 데이터 출력
	_delay_ms(2);	// 0.002초 간격으로 전환
}

void FND_4(int order, char *inf)	// Segment Image 배열
{
	for(int i = 0; i < sm; i++)
	{
		if(i == order) continue;
		else seg(i, *(inf+i));	// seg(i, inf[i]));
	}
	_delay_ms(2);
}


char* SegDisp (int timedigit, unsigned long num)	// 10진 정수 ==> 문자열로 FND_4
{
	// 10진 정수 계산
	int n4 = (num / 1000) % 10;	// D
	int n3 = (num / 100) % 10;	// C
	int n2 = (num / 10) % 10;	// B
	int n1 = num % 10;			// A
	
	//// 시간 계산
	//int n4 = (num / 600) % 6;	// D
	//int n3 = (num / 60) % 10;	// C
	//int n2 = (num / 10) % 6;	// B
	//int n1 = num % 10;			// A
		
	// 문자열로 입력
	arr[0] = digit[n1];
	arr[1] = digit[n2];// + 0x80; // 소수점 표시
	arr[2] = digit[n3];// + 0x80; // 소수점 표시
	arr[3] = digit[n4];

	// sm = (num/100) ? ( (num/1000) ? 4 : 3 ) : ( (num/10) ? 2 : 1);	// 출력 자리수 제한 (0이면 표시 안함)
	
	FND_4(timedigit, arr);
	return arr;
}
