#include <stdio.h>

void test01();
void test02();
void test03();
void test04();	// 포인터를 이용한 문자열 입출력함수
void test05();	// 구조체 테스트

int main()
{
	int n;
	void* pF[] = { test01, test02, test03, test04, test05 };
	void (*pFunc)();
	while (1)
	{
		printf("\n");
		printf("1. 함수1 \n");
		printf("2. 함수2 \n");
		printf("3. 함수3 \n");
		printf("4. 함수4 \n");
		printf("5. 함수5 \n");
		printf("0. 종 료 \n");
		printf("= 선택 = \n");

		scanf("%d", &n);
		pFunc = pF[n - 1];
		pFunc();
		
	}

	//test01();
	//test02();
	//test03();
	//test04();
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
		char *name;
	}s1 = { 1, 3.14 };	// "삼천갑자동방삭
	s1.name = "삼천갑자동방삭";

	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));	// 총 byte 수 출력 : 4+4+8(주소) = 16


	printf("struct stTest s1 : %d %f %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest s2 : %d %f %s\n", s2.i, s2.a, s2.name);
}