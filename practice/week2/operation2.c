#include <stdio.h>

int main()
{
	int x = 4;
	int y = 2;
	int z; // x,y�� �������̸� x, y, z ��� int����

	z = (x + y) * (x - y);
	printf("z = (x + y) * (x - y) = %d\n", z); // x, y�� �̷���� ������ z�ιް� �װ� ����Ʈ�ض�

	z = (x * y) + (x / y);
	printf("z = (x * y) + (x / y) = %d\n", z); // ����

	z = x + y + 2004;
	printf("z = x + y + 2004 = %d\n", z); // x, y �׸��� ���������� �̷���� ������ �޾Ƽ� z�� ����Ʈ�ض�

	return 0;

}
