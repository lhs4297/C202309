#include <stdio.h>

int multiF(int value);

int main()
{
	printf("1����     2������ ���� %d\n", multiF(2));   // 1���� 2������ ���� ���
	printf("1����   3������ ���� %d\n", multiF(3));   // 1���� 3������ ���� ���
	printf("1���� 5������ ���� %d\n", multiF(5));   // 1���� 5������ ���� ���

	return 0;
}

int multiF(int value)
{
	int i;
	int gop = 1;

	for (i = 1; i <= value; i = i + 1)
	{
		gop = gop * i; // 1���� value������ ���� ���
	}

	return gop; // ���� ����� ��ȯ
}
