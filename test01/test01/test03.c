#include <stdio.h>

void test04();	// �����͸� �̿��� ���ڿ� ������Լ�

int main()
{
	test04();
}

void test04()
{
	char* arr[10] = { "aaaaa", "bbbb", "ccc", "dd", "eeeee"};	//������ �迭
	char buf[100];	// �Է°��� ���� buffer ���� ����
	scanf("%s", buf);
	arr[6] = buf;
	scanf("%s", buf+50);
	arr[7] = buf+50;

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x %s\n", i, arr[i], arr[i]);

	}
}