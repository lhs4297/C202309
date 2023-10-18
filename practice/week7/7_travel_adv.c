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

	//사용자로부터 도시 이름 입력받기
	printf("%d개의 도시명을 차례대로 입력해 주세요.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));

	}
	//여행자 이름 입력받기
	printf("%d개의 여행자 이름을 차례대로 입력해주세요.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}

	calculateTravelDays();

	return 0;
}

// 각 도시에서 보낸 총 일수 계산하는 함수
int getSum(int numArray[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += numArray[i];
	}
	return sum;
}

// 각 도시에서 보낸 평균 일수를 계산하기 위한 함수
double getAverage(int numArray[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += numArray[i];
	}
	double averageDays = (double)sum / size;
	return averageDays;
}


// 인기있는 도시와 평균 머문 일 수 구하는 함수
void printFamousCity(double dayArray[], int size) {
	double maxDay = -1.0;
	int maxDayIndex;

	for (int index = 0; index < size; index++) {
		if (dayArray[index] > maxDay) {
			maxDayIndex = index;
			maxDay = dayArray[index];
		}
	}

	printf("가장 인기 있는 도시는 %s이며, 평균 머문 일 수는 %.2f입니다.\n", cities[maxDayIndex], maxDay);

}

void calculateTravelDays() {

	//각 여행자가 각도시에 머무른 날짜를 저장하는 배열 선언 
	int travelDays[NUMPEOPLE][NUMCITY];

	//각 여행자가 각도시에 머무른 날짜를 입력받는 코드 
	for (int i = 0; i < NUMPEOPLE; i++) {
		for (int j = 0; j < NUMCITY; j++) {
			printf("사람 %s가 도시 %s에서 보낸 일 수를 입력하세요: ", names[i], cities[j]);
			scanf_s("%d", &travelDays[i][j]);

		}
	}

	//각 도시별 평균 체류일을 계산하는 함수 호출
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

		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2f\n", cities[i], getSum(cityArray, NUMPEOPLE), averageDays[i]);
	}

	printFamousCity(averageDays, NUMCITY);
}
