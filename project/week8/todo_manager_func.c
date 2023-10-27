#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϱ� ���� 2���� �迭
int taskCount = 0; // �� ���� ���� �����ϱ� ���� ����


// ���� �����ϴ� �Լ�
void addTask(char tasks[][CHAR_NUM], int taskCount) {
	printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", tasks[taskCount], CHAR_NUM);
	printf("�� �� ""%s""�� ����Ǿ����ϴ�\n", tasks[taskCount]);

}


// ���� �����ϴ� �Լ�
void delTask(int delIndex, int taskCount) {
	printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
	scanf_s("%d", &delIndex);
	if (delIndex > taskCount || delIndex <= 0) {
		printf("���� ������ ������ϴ�.\n");
	}
	else {
		printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);

		// �迭�� ���� (=�迭�� ���� �迭�� ���ڿ��� ����) �� �Ұ����ϱ� ������
		// ���ڿ� ���� �Լ��� ����
		strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

		// Ư�� �ε����� �� �� ���� �� �ڿ� �ִ� �� �� ������ �ű��
		for (int i = delIndex; i < taskCount + 1; i++) {
			strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
		}
	}

}

// ���� ��� �ҷ����� �Լ�
void printTask(int taskCount) {
	printf("�� �� ���\n");
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]);
	}
	printf("\n");
}

// ���� �����ϴ� �Լ�
void modifyTask(int delIndex, char tasks[][CHAR_NUM], int taskCount) {
	printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
	scanf_s("%d", &delIndex);
	if (delIndex > taskCount || delIndex <= 0) {
		printf("��ȣ�� ������ ������ϴ�.\n");
	}
	else {   // �����ϴ� �Լ� �����ؼ� �����ϴ� �Լ��� �ٲ�
		printf("���ο� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
		scanf_s("%s", tasks[taskCount], CHAR_NUM);
		strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), tasks[taskCount]);   // �迭�� �ִ� index�� %S���� �޾ƿ� ������ �����
		printf("���ο� �� ""%s""�� ����Ǿ����ϴ�\n", tasks[taskCount]);
	}

}

int main() {



	printf("TODO ����Ʈ ����! \n");

	while (1) {

		// taskCount �� 10���� �Ǹ� �����ϰ� �ƴϸ� ���� main�Լ��� ����
		if (taskCount == 10) {
			printf("------------------------------------------\n");
			printf("������ �� á���ϴ�. ���α׷��� �����մϴ�.\n");
			printf("------------------------------------------\n");
			break;
		}
		else {



			int choice = -1; // ������ �����ϱ�  ���� -1�� ������ �ʱ�ȭ����

			// ����ڿ��� �޴��� ����ϰ�, �޴��� �Է¹ޱ�
			printf("------------------\n");
			printf("�޴��� �Է����ּ���.\n");;
			printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5.�� �� ����\n");
			printf("���� �� �� �� = %d\n", taskCount);
			printf("------------------\n");
			scanf_s("%d", &choice);

			int terminate = 0; // ���Ḧ ���� flag
			int delIndex = -1;  // �� �� ������ ���� index ���� ����
			int changeIndex = -1; // �� �� ������ ���� index ���� ����
			char ch; // �� �� ������ ���۸� �ޱ� ���� ���� ����




			// �Է¿� ���� ��� ����
			switch (choice) {
			case 1:
				addTask(tasks, taskCount);
				taskCount++;
				break;
			case 2:
				// �� �� �����ϴ� �ڵ� ���
				delTask(delIndex, taskCount);
				taskCount -= 1;
				break;
			case 3:
				printTask(taskCount);
				break;
			case 4:
				terminate = 1;
				break;
			case 5:  // ���� �����ϴ� �Լ� �߰�
				modifyTask(delIndex, tasks, taskCount);
				break;
			default:
				printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
			}

			if (terminate == 1) {
				printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
				break;
			}
		}


	}
}