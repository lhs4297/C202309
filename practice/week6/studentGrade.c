#include <stdio.h>
#define STUDENTS 5

// �л� ���� �з��ϴ� �Լ�
void classifyStudents(int scores[], char targetGrade) {
	printf("�л� ���� �з�:\n");   // �л� ���� �з��� ����ϴ� �κ�
	char grade = ' ';   // ������ ������ ����
	for (int i = 0; i < STUDENTS; i++) {
		if (scores[i] >= 90) {   // 90 �̻��̸� A ����
			grade = 'A';
		}
		else if (scores[i] >= 80) {   // 80 �̻��̸� B ����
			grade = 'B';
		}
		else if (scores[i] >= 70) {   // 70 �̻��̸� C ����
			grade = 'C';
		}
		else if (scores[i] >= 60) {   // 60 �̻��̸� D ����
			grade = 'D';
		}
		else {   // 60 �̸��̸� F ����
			grade = 'F';
		}
		if (targetGrade == grade) {   // ��ǥ ������ �л��� ������ ��ġ�ϴ� ���
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1, targetGrade);
		}
	}
}

int main() {
	int scores[STUDENTS];   // �л����� ������ ������ �迭

	for (int i = 0; i < STUDENTS; i++) {
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &scores[i]);   // �л����� ������ �Է¹���
	}

	char ch = getchar();   // ���ۿ� �����ִ� ���� ���ڸ� �����ϱ� ���� ���

	char target;
	printf("Ư�� ���� (A, B, C, D, F)�� �Է��Ͻÿ�: ");
	scanf_s("%c", &target, 1);   // Ư�� ����(A, B, C, D, F)�� �Է¹���

	classifyStudents(scores, target);   // classifyStudents �Լ��� ȣ���Ͽ� �л� ������ �з�

	return 0;
}
