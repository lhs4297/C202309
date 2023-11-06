#include <stdio.h>

int hapf(int value);

int main()
{
	printf("1부터     10까지의 합은 %d", hapf(10));   // 1부터 10까지의 합을 출력
	printf("1부터   100까지의 합은 %d", hapf(100));   // 1부터 100까지의 합을 출력
	printf("1부터 1000까지의 합은 %d", hapf(1000));   // 1부터 1000까지의 합을 출력

	return 0;
}

int hapf(int value)
{
	int i = 1;
	int hap = 0;

	while (i <= value)
	{
		hap += i; // 1부터 value까지의 수를 누적하여 합을 계산
		i++;
	}

	return hap; // 계산된 합을 반환
