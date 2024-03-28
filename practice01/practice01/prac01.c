#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "MyHeader.h"
#define PI 3.14

void prac00();
void prac01();
void prac02();
void prac03();
void prac04();
void prac05();
void prac06();
void prac07();

main()
{
	// prac01();
	// prac01();
	// prac02();
	// prac03();
	// prac04();
	// prac05();
	// prac06();
	prac07();
}

// ===== 함수의 설계 =====
// Prototype : prac00()
// 함수명 : prac00
// 기  능 : 문자열을 입력받아 한 문자씩 띄어서 출력, 대문자로 일괄 변환하여 출력
// 인  수 : 
// 리턴값 : 
void prac00()
{
	int i = 0;
	char buf1[100];
	char* ptr1 = buf1;

	printf("> 문자열을 입력하세요 : ");
	scanf("%s", ptr1);

	//띄어쓰기
	while (*(ptr1 + i))
	{
		printf("%c ", *(ptr1 + i));
		i++;
	}
	printf("\n");
	i = 0;

	//대문자
	while (*(ptr1 + i))
	{
		*(ptr1 + i) = toupper(*(ptr1 + i));
		printf("%c", *(ptr1 + i));
		i++;
	}
	printf("\n");
}

// ===== 함수의 설계 =====
// Prototype : prac01()
// 함수명 : prac01
// 기  능 : ASCII 코드표 출력
// 인  수 : 
// 리턴값 : 
void prac01()
{
	printf("Dec Hex Chr \n");

	for (int i = 0; i < 128; i++)
	{
		printf("%3d %3X %c\n", i, i, i);
	}
}

// ===== 함수의 설계 =====
// Prototype : prac02()
// 함수명 : prac02
// 기  능 : 두 수를 입력받아 출력하고, 두 변수의 값을 바꾸어 다시 출력
// 인  수 : 
// 리턴값 : 
void prac02()
{
	int num1 = 0;
	int num2 = 0;
	int tmp;

	printf("> swap할 두 수를 입력하세요.\n");
	printf("num1 : ");
	scanf("%d", &num1);
	printf("num2 : ");
	scanf("%d", &num2);

	printf("swap 전[0001] %d - [0002] %d\n", num1, num2);
	tmp = num1;
	num1 = num2;
	num2 = tmp;
	printf("swap 후[0001] %d - [0002] %d\n", num1, num2);
}

// ===== 함수의 설계 =====
// Prototype : prac03()
// 함수명 : prac03
// 기  능 : 홀수를 한개 입력받아 *’표 피라미드를 출력
// 인  수 : 
// 리턴값 : 
void prac03()
{
	int num = 0;
	int err;
	// scanf 오류시 buffer clear
	// fflush(stdin);
	// rewind(stdin);

	while (num % 2 != 1)
	{
		printf("> 숫자(홀수)를 입력하시오 : ");
		err = scanf("%d", &num);
		if (err == 0)	// 입력 오류
		{
			fflush(stdin);	// 버퍼 클리어
			rewind(stdin);	// 버퍼 포인터 초기화
			printf("잘못된 입력입니다.\n");
			continue;
		}
	}

	for (int i = 1; i <= num; i = i + 2)
	{
		for (int a = 0; a <= ((num - i) / 2); a++) printf(" ");
		for (int b = 0; b < i ; b++) printf("*");
		for (int c = 0; c <= (num - i) / 2; c++) printf(" ");
		printf("\n");
	}

}

// ===== 함수의 설계 =====
// Prototype : prac04()
// 함수명 : prac04
// 기  능 : 반대 계단식 출력
// 인  수 : 
// 리턴값 : 
void prac04()
{
	char abc;
	printf("> 문자를 입력하시오 : ");
	scanf("%c", &abc);

	int num = abc & 0x0F;
	int count = num;

	while (count > 0)
	{
		for (int i = 0; i < num - count; i++) printf(" ");
		for (int j = 0; j < count; j++) printf("%c", 'A' + num - count);
		printf("\n");
		count--;
	}
}

// ===== 함수의 설계 =====
// Prototype : prac05()
// 함수명 : prac05
// 기  능 : 두 수를 입력받아 최대공약수 출력
// 인  수 : 
// 리턴값 : 
void prac05()
{
	int num1 = 0;
	int num2 = 0;
	int cdnum1[100] = { 0 };
	int cdnum2[100] = { 0 };
	int count = 0;
	int GCD = 0;

	printf("> 두 수를 입력하세요.\n");
	printf("num1 : ");
	scanf("%d", &num1);
	printf("num2 : ");
	scanf("%d", &num2);

	for (int i = 1; i <= num1; i++)	{
		if (num1 % i == 0) cdnum1[count++] = i;
	}
	count = 0;

	for (int i = 1; i <= num2; i++)	{
		if (num2 % i == 0) cdnum2[count++] = i;
	}
	count = 0;

	printf("\n%d : ", num1);
	while (cdnum1[count]) printf("%d ", cdnum1[count++]);
	count = 0;

	printf("\n%d : ", num2);
	while (cdnum2[count]) printf("%d ", cdnum2[count++]);
	count -= 1;

	while (count >= 0)
	{
		for (int i = 0; cdnum1[i]; i++)
		{
			if (cdnum2[count] == cdnum1[i])
				GCD = cdnum2[count];
		}
		if (GCD != 0) break;
		else count--;
	}
	printf("\n%d과 %d의 최대공약수는 %d입니다.\n", num1, num2, GCD);
}

// ===== 함수의 설계 =====
// Prototype : prac06()
// 함수명 : prac06
// 기  능 : SIN 곡선 모양으로 출력
// 인  수 : 
// 리턴값 : 
void prac06()
{
	double y = 1.05;
	while (y >= -1.05)
	{
		for (int i = 0; i < 360; i += 2 )
		{
			if ((sin(i * PI / 180) < y + 0.02) && (sin(i * PI / 180) > y - 0.02)) printf("*");
			else printf(" ");
		}
		printf("\n");
		y -= 0.05;
	}


	for (double x = 0; x < 360; x += 5)
	{
		int val = (int)(100 * (sin(x * PI / 180) + 1));
		for (; val > 0; val -= 2)
			printf(" ");
		printf("*\n");
	}

}

// ===== 함수의 설계 =====
// Prototype : prac07()
// 함수명 : prac07
// 기  능 : MyHeader.h 파일을 이용
// 인  수 : 
// 리턴값 : 
void prac07()
{
	int num;
	printf("> 정수를 입력하세요 : ");
	scanf("%d", &num);
	printf("절댓값은 %d입니다.\n", abs(num));

}
