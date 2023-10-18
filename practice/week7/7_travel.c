#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2  // ������ �ʴ� ���� define���� �������ֱ�


int main() {

	char citynames[NUMCITY][10];
	char names[NUMPEOPLE][10];

	// 1. ���ø� �Է� �ޱ�
	printf("%d���� ���ø��� ���ʴ�� �Է��ϼ���.", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", citynames[i], (int)sizeof(citynames[i]));
	}

	// 2. ���ø� �Է� �ޱ�
	printf("%d���� ������ �̸��� ���ʴ�� �Է��ϼ���.", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}

	//3. ���� �� �����ڵ��� ü���� �Է¹ޱ�
	int travelDays[NUMCITY][NUMPEOPLE];
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("���� %s���� ��� %s�� ���� �� ���� �Է��ϼ���: ", citynames[i], names[i]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}

	// 4. ���� �� ü���� ��� ���ϱ�
	for (int i = 0; i < NUMCITY; i++) {
		int sum = 0;
		float average = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {
			sum += travelDays[i][j];
		}
		average = sum / (float)NUMPEOPLE; // average = sum / NUMPEOPLE;
		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2f\n", citynames[i], sum, average);
	}
	return 0;
}
