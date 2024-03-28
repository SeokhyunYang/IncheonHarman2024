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

// ===== �Լ��� ���� =====
// Prototype : prac00()
// �Լ��� : prac00
// ��  �� : ���ڿ��� �Է¹޾� �� ���ھ� �� ���, �빮�ڷ� �ϰ� ��ȯ�Ͽ� ���
// ��  �� : 
// ���ϰ� : 
void prac00()
{
	int i = 0;
	char buf1[100];
	char* ptr1 = buf1;

	printf("> ���ڿ��� �Է��ϼ��� : ");
	scanf("%s", ptr1);

	//����
	while (*(ptr1 + i))
	{
		printf("%c ", *(ptr1 + i));
		i++;
	}
	printf("\n");
	i = 0;

	//�빮��
	while (*(ptr1 + i))
	{
		*(ptr1 + i) = toupper(*(ptr1 + i));
		printf("%c", *(ptr1 + i));
		i++;
	}
	printf("\n");
}

// ===== �Լ��� ���� =====
// Prototype : prac01()
// �Լ��� : prac01
// ��  �� : ASCII �ڵ�ǥ ���
// ��  �� : 
// ���ϰ� : 
void prac01()
{
	printf("Dec Hex Chr \n");

	for (int i = 0; i < 128; i++)
	{
		printf("%3d %3X %c\n", i, i, i);
	}
}

// ===== �Լ��� ���� =====
// Prototype : prac02()
// �Լ��� : prac02
// ��  �� : �� ���� �Է¹޾� ����ϰ�, �� ������ ���� �ٲپ� �ٽ� ���
// ��  �� : 
// ���ϰ� : 
void prac02()
{
	int num1 = 0;
	int num2 = 0;
	int tmp;

	printf("> swap�� �� ���� �Է��ϼ���.\n");
	printf("num1 : ");
	scanf("%d", &num1);
	printf("num2 : ");
	scanf("%d", &num2);

	printf("swap ��[0001] %d - [0002] %d\n", num1, num2);
	tmp = num1;
	num1 = num2;
	num2 = tmp;
	printf("swap ��[0001] %d - [0002] %d\n", num1, num2);
}

// ===== �Լ��� ���� =====
// Prototype : prac03()
// �Լ��� : prac03
// ��  �� : Ȧ���� �Ѱ� �Է¹޾� *��ǥ �Ƕ�̵带 ���
// ��  �� : 
// ���ϰ� : 
void prac03()
{
	int num = 0;
	int err;
	// scanf ������ buffer clear
	// fflush(stdin);
	// rewind(stdin);

	while (num % 2 != 1)
	{
		printf("> ����(Ȧ��)�� �Է��Ͻÿ� : ");
		err = scanf("%d", &num);
		if (err == 0)	// �Է� ����
		{
			fflush(stdin);	// ���� Ŭ����
			rewind(stdin);	// ���� ������ �ʱ�ȭ
			printf("�߸��� �Է��Դϴ�.\n");
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

// ===== �Լ��� ���� =====
// Prototype : prac04()
// �Լ��� : prac04
// ��  �� : �ݴ� ��ܽ� ���
// ��  �� : 
// ���ϰ� : 
void prac04()
{
	char abc;
	printf("> ���ڸ� �Է��Ͻÿ� : ");
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

// ===== �Լ��� ���� =====
// Prototype : prac05()
// �Լ��� : prac05
// ��  �� : �� ���� �Է¹޾� �ִ����� ���
// ��  �� : 
// ���ϰ� : 
void prac05()
{
	int num1 = 0;
	int num2 = 0;
	int cdnum1[100] = { 0 };
	int cdnum2[100] = { 0 };
	int count = 0;
	int GCD = 0;

	printf("> �� ���� �Է��ϼ���.\n");
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
	printf("\n%d�� %d�� �ִ������� %d�Դϴ�.\n", num1, num2, GCD);
}

// ===== �Լ��� ���� =====
// Prototype : prac06()
// �Լ��� : prac06
// ��  �� : SIN � ������� ���
// ��  �� : 
// ���ϰ� : 
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

// ===== �Լ��� ���� =====
// Prototype : prac07()
// �Լ��� : prac07
// ��  �� : MyHeader.h ������ �̿�
// ��  �� : 
// ���ϰ� : 
void prac07()
{
	int num;
	printf("> ������ �Է��ϼ��� : ");
	scanf("%d", &num);
	printf("������ %d�Դϴ�.\n", abs(num));

}
