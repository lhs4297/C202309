#include <stdio.h>

int main()
{
	int x = +4;
	int y = -2;

	printf("x + (-y) = %d\n", x + (-y)); // ��ȣ�� �̿��� int ������ ������ print�� �ȿ��� �ѹ��� �޾Ƽ� ���
	printf("-x + (+y) = %d\n", -x + (+y));

	return 0;

}