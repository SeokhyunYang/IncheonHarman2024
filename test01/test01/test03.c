#include <stdio.h>

void test04();	// 포인터를 이용한 문자열 입출력함수

int main()
{
	test04();
}

void test04()
{
	char* arr[10] = { "aaaaa", "bbbb", "ccc", "dd", "eeeee"};	//포인터 배열
	char buf[100];	// 입력값을 받을 buffer 공간 생성
	scanf("%s", buf);
	arr[6] = buf;
	scanf("%s", buf+50);
	arr[7] = buf+50;

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x %s\n", i, arr[i], arr[i]);

	}
}