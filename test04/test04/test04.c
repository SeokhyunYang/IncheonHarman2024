#include <stdio.h>
#include <conio.h>
#include <string.h>

void test01();
void test02();
void test03();
void test04();	// 포인터를 이용한 문자열 입출력함수
void test05();	// 구조체 테스트
void test06();	// 표준 문자열 
void test07();	// 문자열 길이
void test08();	// 문자열 비교
void Copy(char* p1, char* p2);
void Dump(char* p, int len);
int Length(char* str1);
int Compare(char* str1, char* str2);
 
int main()
{
	int n;
	void* pf[] = { test01, test02, test03, test04, test05, test06, test07, test08 };
	void (*pfunc)();
	while (1)
	{
		printf("\n");
		printf("1. 함수1 \n");
		printf("2. 함수2 \n");
		printf("3. 함수3 \n");
		printf("4. 함수4 : 포인터를 이용한 문자열 입출력함수 \n");
		printf("5. 함수5 : 구조체 테스트 \n");
		printf("6. 함수6 : 표준 문자열 \n");
		printf("7. 함수7 : 입력한 문자열의 길이 출력 \n");
		printf("8. 함수8 : 입력한 문자열 비교 \n");
		printf("0. 종 료 \n");
		printf("= 선택 = \n");
		scanf("%d", &n);
		pfunc = pf[n - 1];
		pfunc();
	}

}

void test01() { printf("01\n"); }
void test02() { printf("02\n"); }
void test03() { printf("03\n"); }
void test04()
{
	printf("test04\n");

	char* arr[10] = { "aaaaa", "bbbb", "ccc", "dd", "eeeee" };	//포인터 배열
	char buf[100];	// 입력값을 받을 buffer 공간 생성
	scanf("%s", buf);
	arr[6] = buf;
	scanf("%s", buf + 50);
	arr[7] = buf + 50;

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x %s\n", i, arr[i], arr[i]);

	}
}
void test05()
{
	struct stTest
	{
		int i;
		float a;
		char* name;
	}s1 = { 1, 3.14 };	// "삼천갑자동방삭
	s1.name = "삼천갑자동방삭";

	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));	// 총 byte 수 출력 : 4+4+8(주소) = 16


	printf("struct stTest s1 : %d %f %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest s2 : %d %f %s\n", s2.i, s2.a, s2.name);
}
void test06()
{
	char* s1 = "Good";
	char* s2 = "afternoon";
	char buf[100];

	// strcat Test
	printf("s1 : %s (%d)\n", s1, strlen(s1));
	printf("s2 : %s (%d)\n", s2, strlen(s2));
	// printf("strcat(s1,s2) : %s", strcat(s1,s2));
	//sprintf(buf, "strcat(s1,s2) : %s%s\n", s1, s2);
	//printf("%s", buf);

	strcpy(buf, s1);
	strcat(buf, s2);
	printf("strcat(s1,s2) : %s", buf);

}
void test07()
{
	char* buf[100];
	printf("문자열을 입력하세요. :");
	scanf("%s", buf);
	printf("입력한 문자열의 길이는 [ %d ] 입니다.\n", Length(buf));
}
void test08()
{
	char* buf1 [100];
	char* buf2 [100];

	printf("비교할 문자열을 입력하세요.\n");
	printf("문자열1 :");
	scanf("%s", buf1);
	printf("문자열2 :");
	scanf("%s", buf2);

	if (Compare(buf1, buf2) == 0) printf("두 문자열이 일치합니다.\n");
	else if (Compare(buf1, buf2) == -1) printf("문자열1이 문자열2보다 작습니다.\n");
	else if (Compare(buf1, buf2) == 1) printf("문자열1이 문자열2보다 큽니다.\n");

}

// ===== 함수의 설계 =====
// Prototype : void Copy(char *p1, char& p2)
// 함수명 : Copy
// 기  능 : p2 문자열을 인수로 받아서 p1 문자열로 복사
// 인  수 : 타겟 문자열, 소스 문자열 - char *p1, char *p2
// 리턴값 : void
void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}

void Dump(char* p, int len)	// 메모리 공간 출력 함수
{
	for (int i = 0; i < len; i++)	// 안전 메모리 공간 덤프
	{
		if (i % 16 == 0)	printf("\n%08x ", p);
		if (i % 8 == 0) printf("   ");
		printf("%02x ", (unsigned char)*p++);
	}
}

// ===== 함수의 설계 =====
// Prototype : int Length(char* str)
// 함수명 : Length
// 기  능 : 문자열을 인수로 받아서 문자열의 길이를 반환
// 인  수 : 문자열 - char *str
// 리턴값 : 문자열의 길이 - int len
int Length(char *str1)
{
	int len = 0;

	while (*(str1 + len))	len++;

	return len;

}

// ===== 함수의 설계 =====
// Prototype : Compare(char* str1, char* str2)
// 함수명 : Compare
// 기  능 : 두 문자열을 인수로 받아서 문자열의 크기를 비교
// 인  수 : 문자열1, 문자열2 - char *str1, char *str2
// 리턴값 : -1(문자열1 < 문자열2), 0(문자열1 = 문자열2), 1(문자열1 > 문자열2)
int Compare(char* str1, char* str2)
{
	do
	{
		if (*str1 == *str2) {
			str1++;
			str2++;
		}
		else if (*str1 < *str2) return -1;
		else if (*str1 > *str2) return 1;
	} while ((*(str1 - 1)) && (*(str2 - 1)));

	return 0;
}