#include <stdio.h>

int main() {
    int choice;   //choice�� int Ÿ������ �ްڴ�

    printf("1. ���� ����\n");
    printf("2. ���� ���� �ݱ�\n");
    printf("3. ����\n");

    scanf_s("%d", &choice);   // ����ڿ��� �Է¹��� ���ڸ� choice�� ��´�

    if (choice == 1) {   // ���� choice�� 1�̶�� ����
        printf("������ �����մϴ�.\n");
    }
    else if (choice == 2) {   // ���� if���� �����̰� choice�� 2��� �����ض�
        printf("������� �ݽ��ϴ�.\n");
    }
    else if (choice == 3) {   
        printf("�����մϴ�.\n");
    }
    else {   // ���� if������ ��� �����̶�� �� ������ �����ض�
        printf("�߸� �Է��ϼ̽��ϴ�.\n");
    }

    return 0;
}
