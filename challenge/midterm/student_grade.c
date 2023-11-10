#include <stdio.h>

#define STUDENTS 5   // �л� ��, ���� ��, ���ڿ� ���̸� ����
#define SUBJECTS 3
#define CHARNUM 20

void printStudentResults(char studentNames[][CHARNUM], double studentScores[][SUBJECTS]) {   // �л� �� ��� ������ ����ϰ� ����ϴ� �Լ�
    printf("�л� �� ������ ������ �����ϴ�.\n");
    for (int i = 0; i < STUDENTS; i++) {
        double sum = 0.0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += studentScores[i][j];   // �� �л��� ���� �հ踦 ���
        }
        printf("\t%s�� ��� ����: %.2f\n", studentNames[i], sum / SUBJECTS);   // �л��� ��� ������ ���
    }
    printf("----------------------------\n");
}

void printSubjectResults(char subjectNames[][CHARNUM], double studentScores[][SUBJECTS]) {   // ���� �� ��� ������ ����ϰ� ����ϴ� �Լ�
    printf("���� �� ��� ������ �Ʒ��� �����ϴ�.\n");
    for (int i = 0; i < SUBJECTS; i++) {
        double sum = 0.0;
        for (int j = 0; j < STUDENTS; j++) {
            sum += studentScores[j][i];   // �� ������ ���� �հ踦 ���
        }
        printf("\t%s�� ��� ����: %.2f �Դϴ�.\n", subjectNames[i], sum / STUDENTS);   // ������ ��� ������ ���
    }
    printf("���α׷��� �����մϴ�.\n");
}

int main() {
    char subjectNames[SUBJECTS][CHARNUM] = { "����", "�߰����", "�⸻���" };   // ���� �̸��� ����
    char studentNames[STUDENTS][CHARNUM];   // �л� �̸��� ������ �迭 ����
    double studentScores[STUDENTS][SUBJECTS];   // �л� ������ ������ �迭 ����

    printf("�л� %d���� �̸��� �Է��� �����մϴ�.\n", STUDENTS);

    for (int i = 0; i < STUDENTS; i++) {
        printf("\t%d��° �л��� �̸��� �Է��ϼ���: ", i + 1);
        fgets(studentNames[i], CHARNUM, stdin);   // �л� �̸� �Է� ����
        studentNames[i][strcspn(studentNames[i], "\n")] = 0;   // ���� ���ڸ� null ���ڷ� ����
    }
    printf("�л� �̸��� ��� �ԷµǾ����ϴ�.");
    printf("\n�Էµ� �л� �̸��� ������ �����ϴ�.\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("%s,", studentNames[i]);   // �Էµ� �л� �̸� ���
    }
    printf("\n----------------------------\n");

    printf("�� �л��� ����, �߰����, �⸻��� ������ ���ʴ�� �Է��ϼ���\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("\t%s�� ����: ", studentNames[i]);
        for (int j = 0; j < SUBJECTS; j++) {
            scanf_s("%lf", &studentScores[i][j]);   // �л� ���� �Է� ����
        }
        getchar(); // ���۸� ���� �ڵ� �߰�
    }
    printf("�л����� ���� ������ ��� �Է� �Ǿ����ϴ�.\n");
    printf("----------------------------\n");

    printStudentResults(studentNames, studentScores);   // �л� �� ��� ���� ��� �� ����ϴ� �Լ� ȣ��
    printSubjectResults(subjectNames, studentScores);   // ���� �� ��� ���� ��� �� ����ϴ� �Լ� ȣ��

    return 0;
}
