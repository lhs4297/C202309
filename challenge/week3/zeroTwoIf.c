#include <stdio.h>

int main() {
	int num = 0;
	printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s("%d", &num);
	
    if (num == 0) {   // ���� num�� 0�̶�� ����
        printf("zero");
    }
    else if (num == 1) {   // ���� ������ �ƴϸ鼭 num�� 1 �̶�� �����ض�
        printf("one");
    }
    else if (num == 2) {   // ���� ������ �ƴϸ鼭 num�� 2 �̶�� �����ض�
        printf("two");
    }
    else {   // ���� if������ ��� �����̶�� �� ������ �����ض�
        printf("not 0 ~ 2");
    }

    return 0;
}