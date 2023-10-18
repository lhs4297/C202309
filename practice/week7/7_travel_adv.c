#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10];
char cities[NUMCITY][10];

void calculateTravelDays();
int getSum(int numArray[], int size);
double getAverage(int numArray[], int size);
void printFamousCity(double dayArray[], int size);
void averageTravelDays(int travelDays[][NUMCITY]);

int main() {

	//����ڷκ��� ���� �̸� �Է¹ޱ�
	printf("%d���� ���ø��� ���ʴ�� �Է��� �ּ���.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));

	}
	//������ �̸� �Է¹ޱ�
	printf("%d���� ������ �̸��� ���ʴ�� �Է����ּ���.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}

	calculateTravelDays();

	return 0;
}

// �� ���ÿ��� ���� �� �ϼ� ����ϴ� �Լ�
int getSum(int numArray[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += numArray[i];
	}
	return sum;
}

// �� ���ÿ��� ���� ��� �ϼ��� ����ϱ� ���� �Լ�
double getAverage(int numArray[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += numArray[i];
	}
	double averageDays = (double)sum / size;
	return averageDays;
}


// �α��ִ� ���ÿ� ��� �ӹ� �� �� ���ϴ� �Լ�
void printFamousCity(double dayArray[], int size) {
	double maxDay = -1.0;
	int maxDayIndex;

	for (int index = 0; index < size; index++) {
		if (dayArray[index] > maxDay) {
			maxDayIndex = index;
			maxDay = dayArray[index];
		}
	}

	printf("���� �α� �ִ� ���ô� %s�̸�, ��� �ӹ� �� ���� %.2f�Դϴ�.\n", cities[maxDayIndex], maxDay);

}

void calculateTravelDays() {

	//�� �����ڰ� �����ÿ� �ӹ��� ��¥�� �����ϴ� �迭 ���� 
	int travelDays[NUMPEOPLE][NUMCITY];

	//�� �����ڰ� �����ÿ� �ӹ��� ��¥�� �Է¹޴� �ڵ� 
	for (int i = 0; i < NUMPEOPLE; i++) {
		for (int j = 0; j < NUMCITY; j++) {
			printf("��� %s�� ���� %s���� ���� �� ���� �Է��ϼ���: ", names[i], cities[j]);
			scanf_s("%d", &travelDays[i][j]);

		}
	}

	//�� ���ú� ��� ü������ ����ϴ� �Լ� ȣ��
	averageTravelDays(travelDays);
}


void averageTravelDays(int travelDays[][NUMCITY]) {

	double averageDays[NUMCITY];

	for (int i = 0; i < NUMCITY; ++i) {
		int cityArray[NUMPEOPLE];

		for (int j = 0; j < NUMPEOPLE; ++j) {
			cityArray[j] = travelDays[j][i];
		}

		averageDays[i] = getAverage(cityArray, NUMPEOPLE);

		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2f\n", cities[i], getSum(cityArray, NUMPEOPLE), averageDays[i]);
	}

	printFamousCity(averageDays, NUMCITY);
}
