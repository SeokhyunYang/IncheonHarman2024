#include <stdio.h>

main()
{
	// ������ ����� �ʱ�ȭ
	char vchar = 'f';
	int vint = 10;
	long vlong = 400000000;
	float vfloat = 3.14159265;
	double vdouble = 314159265.123456789;


	printf("\n�ȳ��ϼ���?\n");
	printf("%8x\n%8x\n%8x\n%8x\n", &vchar, &vint, &vlong, &vfloat);
	scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);

	printf("   ���� ��� �׽�Ʈ : [%12d]\n", vint); // 4byte
	printf("   �Ǽ� ��� �׽�Ʈ : [%12.8f]\n", vfloat); // 4byte
	printf("�� ���� ��� �׽�Ʈ : [%12d]\n", vlong); // 4byte = 32bit = 1111 1111 1111 1111 1111 1111 1111 1111 -> 4G (~40��)
	printf("   ���� ��� �׽�Ʈ : [%12e]\n", vdouble); // 
	printf("  8���� ��� �׽�Ʈ : [%12o]\n", vint); // 
	printf(" 16���� ��� �׽�Ʈ : [%12x]\n", vint); // 
	printf("   ���� ��� �׽�Ʈ : [%c]\n", vchar); // 
	printf("   ���� ���� �׽�Ʈ : [%c]\n", vchar+1); // 
}