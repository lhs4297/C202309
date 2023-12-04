#include <stdio.h>
#include <stdlib.h> 

typedef struct Student { // �л� ������ �����ϱ� ���� ����ü ����
    char name[50]; // �л� �̸��� �����ϴ� ���ڿ�
    int score; // �л��� ������ �����ϴ� ������ ����
} Student; // ����ü ��Ī�� Student�� ����

void classifyStudents(Student* students, int studentCount, char targetGrade) { // �л����� ������ �з��ϴ� �Լ�
    printf("�л� ���� �з�:");
    char grade = ' '; // ������ ������ ����

    // ��� �л��� ����
    for (int i = 0; i < studentCount; i++) {
        // ������ ���� ������ ����
        if (students[i].score >= 90) {
            grade = 'A';
        }
        else if (students[i].score >= 80) {
            grade = 'B';
        }
        else if (students[i].score >= 70) {
            grade = 'C';
        }
        else if (students[i].score >= 60) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }

        // ��ǥ ������ ���� �л��� �ִٸ� ���
        if (targetGrade == grade) {
            printf("%s �л��� %c ������ �޾ҽ��ϴ�.", students[i].name, targetGrade);
        }
    }
}

int sumScores(Student* students, int studentCount) { // �л����� ���� �հ踦 ����ϴ� �Լ�
    int sum = 0; // �հ踦 ������ ����

    // ��� �л��� ����
    for (int i = 0; i < studentCount; i++) {
        sum += students[i].score; // ������ �հ迡 ����
    }

    return sum; // �հ踦 ��ȯ
}

double averageScores(Student* students, int studentCount) { // �л����� ���� ����� ����ϴ� �Լ�
    int sum = sumScores(students, studentCount); // �л����� ���� �հ踦 ���
    double average = (double)sum / (double)studentCount; // ����� ���
    return average; // ����� ��ȯ
}

void printRanks(Student* students, int studentCount) { // �л����� ������ ����ϴ� �Լ�
    int* ranks = (int*)malloc(sizeof(int) * studentCount); // ������ ������ ���� �迭�� ����

    // ��� �л��� ����
    for (int i = 0; i < studentCount; i++) {
        ranks[i] = 1; // �ʱ� ������ 1�� ����

        // ��� �л��� ����
        for (int j = 0; j < studentCount; j++) {
            // �ٸ� �л��� ������ �� ���ٸ� ������ ����
            if (students[j].score > students[i].score) {
                ranks[i]++;
            }
        }

        printf("%s �л��� ������ %d�Դϴ�.", students[i].name, ranks[i]); // ������ ���
    }

    free(ranks); // ���� �迭�� �޸𸮸� ����
}

int main() {
    int studentCount; // �л� ���� ������ ����
    printf("�л� ���� �Է��ϼ���: ");
    scanf_s("%d", &studentCount); // �л� ���� �Է¹���

    Student* students = (Student*)malloc(sizeof(Student) * studentCount); // �л� ������ ������ ���� �迭�� ����

    // ��� �л��� ����
    for (int i = 0; i < studentCount; i++) {
        printf("�л� %d�� �̸��� ������ �Է��ϼ���: ", i + 1);
        scanf_s("%s %d", students[i].name, &(students[i].score)); // �̸��� ������ �Է¹���
    }

    char ch = getchar(); // ���۸� ���

    char target; // ��ǥ ������ ������ ����
    printf("Ư�� ���� (A, B, C, D, F)�� �Է��Ͻÿ�: ");
    scanf_s("%c", &target); // ��ǥ ������ �Է¹���

    classifyStudents(students, studentCount, target); // ������ �з��ϰ� ���

    int sum = sumScores(students, studentCount); // ���� �հ踦 ���
    double average = averageScores(students, studentCount); // ���� ����� ���
    printf("�л��� ������ �� ���� %d�̰�, ��� ���� %lf�Դϴ�.", sum, average); // ���� �հ�� ����� ���

    printRanks(students, studentCount); // ������ ���

    free(students); // �л� ���� �迭�� �޸𸮸� ����

    return 0; // ���α׷� ����
}
