#include <stdio.h>

main()
{
	// 변수의 선언과 초기화
	char vchar = 'f';
	int vint = 10;
	long vlong = 400000000;
	float vfloat = 3.14159265;
	double vdouble = 314159265.123456789;


	printf("\n안녕하세요?\n");
	printf("%8x\n%8x\n%8x\n%8x\n", &vchar, &vint, &vlong, &vfloat);
	scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);

	printf("   정수 출력 테스트 : [%12d]\n", vint); // 4byte
	printf("   실수 출력 테스트 : [%12.8f]\n", vfloat); // 4byte
	printf("긴 정수 출력 테스트 : [%12d]\n", vlong); // 4byte = 32bit = 1111 1111 1111 1111 1111 1111 1111 1111 -> 4G (~40억)
	printf("   지수 출력 테스트 : [%12e]\n", vdouble); // 
	printf("  8진수 출력 테스트 : [%12o]\n", vint); // 
	printf(" 16진수 출력 테스트 : [%12x]\n", vint); // 
	printf("   문자 출력 테스트 : [%c]\n", vchar); // 
	printf("   문자 연산 테스트 : [%c]\n", vchar+1); // 
}