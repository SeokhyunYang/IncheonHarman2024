#include <stdio.h>
#include <conio.h>
#include <string.h>

void test01();
void test02();
void test03();
void test04();	// �����͸� �̿��� ���ڿ� ������Լ�
void test05();	// ����ü �׽�Ʈ
void test06();	// ǥ�� ���ڿ� 
void test07();	// ���ڿ� ����
void test08();	// ���ڿ� ��
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
		printf("1. �Լ�1 \n");
		printf("2. �Լ�2 \n");
		printf("3. �Լ�3 \n");
		printf("4. �Լ�4 : �����͸� �̿��� ���ڿ� ������Լ� \n");
		printf("5. �Լ�5 : ����ü �׽�Ʈ \n");
		printf("6. �Լ�6 : ǥ�� ���ڿ� \n");
		printf("7. �Լ�7 : �Է��� ���ڿ��� ���� ��� \n");
		printf("8. �Լ�8 : �Է��� ���ڿ� �� \n");
		printf("0. �� �� \n");
		printf("= ���� = \n");
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

	char* arr[10] = { "aaaaa", "bbbb", "ccc", "dd", "eeeee" };	//������ �迭
	char buf[100];	// �Է°��� ���� buffer ���� ����
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
	}s1 = { 1, 3.14 };	// "��õ���ڵ����
	s1.name = "��õ���ڵ����";

	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));	// �� byte �� ��� : 4+4+8(�ּ�) = 16


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
	printf("���ڿ��� �Է��ϼ���. :");
	scanf("%s", buf);
	printf("�Է��� ���ڿ��� ���̴� [ %d ] �Դϴ�.\n", Length(buf));
}
void test08()
{
	char* buf1 [100];
	char* buf2 [100];

	printf("���� ���ڿ��� �Է��ϼ���.\n");
	printf("���ڿ�1 :");
	scanf("%s", buf1);
	printf("���ڿ�2 :");
	scanf("%s", buf2);

	if (Compare(buf1, buf2) == 0) printf("�� ���ڿ��� ��ġ�մϴ�.\n");
	else if (Compare(buf1, buf2) == -1) printf("���ڿ�1�� ���ڿ�2���� �۽��ϴ�.\n");
	else if (Compare(buf1, buf2) == 1) printf("���ڿ�1�� ���ڿ�2���� Ů�ϴ�.\n");

}

// ===== �Լ��� ���� =====
// Prototype : void Copy(char *p1, char& p2)
// �Լ��� : Copy
// ��  �� : p2 ���ڿ��� �μ��� �޾Ƽ� p1 ���ڿ��� ����
// ��  �� : Ÿ�� ���ڿ�, �ҽ� ���ڿ� - char *p1, char *p2
// ���ϰ� : void
void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}

void Dump(char* p, int len)	// �޸� ���� ��� �Լ�
{
	for (int i = 0; i < len; i++)	// ���� �޸� ���� ����
	{
		if (i % 16 == 0)	printf("\n%08x ", p);
		if (i % 8 == 0) printf("   ");
		printf("%02x ", (unsigned char)*p++);
	}
}

// ===== �Լ��� ���� =====
// Prototype : int Length(char* str)
// �Լ��� : Length
// ��  �� : ���ڿ��� �μ��� �޾Ƽ� ���ڿ��� ���̸� ��ȯ
// ��  �� : ���ڿ� - char *str
// ���ϰ� : ���ڿ��� ���� - int len
int Length(char *str1)
{
	int len = 0;

	while (*(str1 + len))	len++;

	return len;

}

// ===== �Լ��� ���� =====
// Prototype : Compare(char* str1, char* str2)
// �Լ��� : Compare
// ��  �� : �� ���ڿ��� �μ��� �޾Ƽ� ���ڿ��� ũ�⸦ ��
// ��  �� : ���ڿ�1, ���ڿ�2 - char *str1, char *str2
// ���ϰ� : -1(���ڿ�1 < ���ڿ�2), 0(���ڿ�1 = ���ڿ�2), 1(���ڿ�1 > ���ڿ�2)
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