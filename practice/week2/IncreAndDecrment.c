#include <stdio.h>

int main()
{
	int x = 1;

	printf("x=%d\n", x++);   // ���� ���� �����ڸ� �̿��ؼ� x�� ���� ���� ����ϰ� �� �Ŀ� 1 ����
	printf("x=%d\n", x++);
	printf("x=%d\n", ++x);   // 1��ŭ �����Ͽ� x���� ��� 
	printf("x=%d\n", x--);   // x�� ���簪�� ����ϰ� 1��ŭ ����
	printf("x=%d\n", x--);
	printf("x=%d\n", --x);   // 1��ŭ �����ϰ� x���� ���

	return 0;

}
