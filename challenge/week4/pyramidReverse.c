#include <stdio.h>

int main() {
    int floor;

    printf("�� ���� �װڽ��ϱ�? (5~100) ");
    scanf_s("%d", &floor);   // ���� �Ƕ�̵� �ױ�� ����

    for (int i = floor; i >= 1; --i) {   // �Ƕ�̵�� �ݴ�� i�� 0���� ������ �ƴ� floor���� ���� and 1�� ����
        for (int j = 0; j <= floor - i -1; ++j) {   //floor�� -i -1 �� ��ŭ ����Ҳ���  --> S�� ����� ����� --> �Ƕ�̵� ����� �������
            printf("S");
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {   // *����� 1,3,5,7... ���� ���̰� ��
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
