#include <stdio.h>

int main() {
    int floor;   // floor�� int type���� �ްڴ�

    printf("�� ���� �װڽ��ϱ�? (5~100) ");
    scanf_s("%d", &floor);

    for (int i = 0; i < floor; i++) {   // scanf_s�� ���� floor�� ��ŭ �ݺ��ǰ� �Ѵ�. --> �� ���� �����
        for (int j = 0; j < floor - i - 1; j++) {   // floor�� -i -1 �� ��ŭ ����Ҳ���  --> S�� ����� ����� --> �Ƕ�̵� ����� �������
            printf("S");
        }

        for (int k = 0; k < i * 2 + 1; k++) {   // *����� 1,3,5,7....���� ��µǰ� �������
            printf("*");
        }

        printf("\n");   // ���� ����ϰ� ���� �ٲپ���
    }

    return 0;
}
