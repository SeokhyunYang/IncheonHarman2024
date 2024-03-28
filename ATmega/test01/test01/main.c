#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define __delay_t 500

uint8_t digit[] = {	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7c, 0x58, 0x5e, 0x79, 0x71};
char arr[5]; // Segment를 담을 안전영역

volatile int state = 0;

ISR(INT7_vect)	// 인터럽트 발생했을 때 state 증가
{
	state++;
}

void INIT_INT7(void)
{
	EIMSK = 0x80;			// INT7 인터럽트 활성화 // EIMSK |= (1 << INT7); 
	EICRB = 0xc0;			// 상승 에지에서 인터럽트 발생 // EICRB |= (1 << ISC71)|(1 << ISC70);
	sei();					// set interrupt : 전역적으로 인터럽트 허용
}

void seg(int sel, uint8_t c)
{
	PORTC |= 0x0F;
	PORTC &= (1 << (3-sel));
	PORTD = ~c;		// 숫자 데이터 출력
	_delay_ms(2);	// 0.002초 간격으로 전환
}

void FND_4(char *inf)	// Segment Image 배열
{
	for(int i = 0; i < 4; i++)
	{
		seg(i, *(inf+i));	// seg(i, inf[i]));
	}
}

char* Trans(unsigned long num)	// 10진 정수 ==> 문자열로 FND_4
{
	// 10진 정수 계산
	int n4 = (num / 1000) % 10;	// D
	int n3 = (num / 100) % 10;	// C
	int n2 = (num / 10) % 10;	// B
	int n1 = num % 10;			// A
	
	// 문자열로 입력
	arr[0] = digit[n1];
	arr[1] = digit[n2];
	arr[2] = digit[n3] + 0x80;
	if (n4 == 0)	arr[3] = 0x00;		// n4 자릿수가 0이면 표시 안함
	else			arr[3] = digit[n4];
	
	FND_4(arr);
	return arr;
}

/*
char* Trans(int num)	// 10진 정수 ==> 16진수 문자열 : 65535 ==> 0xFFFF , 56506 ==> 0xDCBA
{
	// 10진 정수 ==> 16진 정수 계산
	int n4 = num / 0x1000;			// D
	int n3 = (num / 0x100) % 0x10;	// C : (num % 0x1000) / 0x100;
	int n2 = (num / 0x10) % 0x10;	// B :(num % 0x100) / 0x10;
	int n1 = num % 0x10;			// A
	
	// 16진 문자열로 입력
	arr[0] = digit[n1];
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	
	FND_4(arr);
	return arr;
}
*/

int main(void)
{
	
	unsigned long j = 0;
	DDRD = 0xFF;		// 세그먼트 제어 핀 8개를 출력으로 설정
	DDRC = 0x0F;		// 자릿수 선택 핀 4개를 출력으로 설정
	DDRE = 0x3F;		// 0011 1111, PE7=0(INT7용 값 입력), PE4=1
	PORTE = 0xE3;		// PE4에 0 출력
	
	INIT_INT7();
	
	while (1)
	{
		//	초기 상태에서는 (----) 표시
		if(state == 0)
		{
			PORTC |= 0x0F;
			PORTD = ~0x40;
			_delay_ms(1000);
		}
		
		
		else if ((state > 0) && (state % 2 == 1))
		{
			Trans(j++);
			_delay_ms(2);
		}
		else{Trans(j);}	// 스위치를 누르면 인터럽트 발생하여 정지
	}
	return 0;
}


