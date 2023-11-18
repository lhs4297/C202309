#include <stdio.h>

#define STUDENTS 5

// �л� ������ �з��ϴ� �Լ�
void classifyStudents(int* scores, char targetGrade) {
    printf("�л� ���� �з�:\n");
    char grade = ' ';   // ������ ������ ���� ����

    for (int i = 0; i < STUDENTS; i++) {   // STUDENTS �� ��ŭ �ݺ�
        if (*(scores + i) >= 90) {
            grade = 'A';
        }
        else if (*(scores + i) >= 80) {
            grade = 'B';
        }
        else if (*(scores + i) >= 70) {
            grade = 'C';
        }
        else if (*(scores + i) >= 60) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }

        if (targetGrade == grade) {
            printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1, targetGrade);
        }
    }
}

int sumScores(int* scores) {   // scores�� int�� �����ͷ�, �迭�� ù ��° ������ �ּҸ� ����Ŵ
    int sum = 0;

    for (int i = 0; i < STUDENTS; i++) {
        sum += *(scores + i);   // *(scores + i)�� i��° �л��� ������ �ǹ�
    }

    return sum;
}

double averageScores(int* scores) {   // scores�� int�� �����ͷ�, �迭�� ù ��° ������ �ּҸ� ����Ŵ
    int sum = sumScores(scores);
    double average = (double)sum / (double)STUDENTS;
    return average;
}

void printRanks(int* scores) {   // scores�� int�� �����ͷ�, �迭�� ù ��° ������ �ּҸ� ����Ŵ
    int ranks[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {   
        *(ranks + i) = 1;   // *(ranks + i)�� i��° ����

        for (int j = 0; j < STUDENTS; j++) {
            if (*(scores + j) > *(scores + i)) {   // *(scores + j)�� *(scores + i)�� ���� j��° �л��� i��° �л��� ����
                (*(ranks + i))++;   // *(ranks + i)�� i��° ������ �ǹ��ϸ�, �̸� ������Ŵ
            }
        }

        printf("%d �л��� ������ %d�Դϴ�.\n", i + 1, *(ranks + i));
    }
}

int main() {
    int scores[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {
        printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
        scanf_s("%d", scores + i);   // scores + i�� i��° �л��� ������ ����Ŵ
    }

    char ch = getchar();   // ���ۿ� �����ִ� ���� ���� ����

    char target;
    printf("Ư�� ���� (A, B, C, D, F)�� �Է��Ͻÿ�: ");
    scanf_s("%c", &target);   // Ư�� ���� �Է� �ޱ�

    classifyStudents(scores, target);

    int sum = sumScores(scores);
    double average = averageScores(scores);
    printf("�л��� ������ �� ���� %d�̰�, ��� ���� %lf�Դϴ�.\n", sum, average);   // ���հ� ��� ���

    printRanks(scores);   // �л����� ���� ���

    return 0;
}
