#include <stdio.h>

int hapf(int value);

int main()
{
	printf("1����     10������ ���� %d", hapf(10));   // 1���� 10������ ���� ���
	printf("1����   100������ ���� %d", hapf(100));   // 1���� 100������ ���� ���
	printf("1���� 1000������ ���� %d", hapf(1000));   // 1���� 1000������ ���� ���

	return 0;
}

int hapf(int value)
{
	int i = 1;
	int hap = 0;

	while (i <= value)
	{
		hap += i; // 1���� value������ ���� �����Ͽ� ���� ���
		i++;
	}

	return hap; // ���� ���� ��ȯ
