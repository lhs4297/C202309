#include <stdio.h>

int multiF(int value);

int main()
{
	printf("1부터     2까지의 곱은 %d\n", multiF(2));   // 1부터 2까지의 곱을 출력
	printf("1부터   3까지의 곱은 %d\n", multiF(3));   // 1부터 3까지의 곱을 출력
	printf("1부터 5까지의 곱은 %d\n", multiF(5));   // 1부터 5까지의 곱을 출력

	return 0;
}

int multiF(int value)
{
	int i;
	int gop = 1;

	for (i = 1; i <= value; i = i + 1)
	{
		gop = gop * i; // 1부터 value까지의 곱을 계산
	}

	return gop; // 곱한 결과를 반환
}
