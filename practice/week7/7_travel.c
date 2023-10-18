#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2  // 변하지 않는 값들 define으로 지정해주기


int main() {

	char citynames[NUMCITY][10];
	char names[NUMPEOPLE][10];

	// 1. 도시명 입력 받기
	printf("%d개의 도시명을 차례대로 입력하세요.", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", citynames[i], (int)sizeof(citynames[i]));
	}

	// 2. 도시명 입력 받기
	printf("%d개의 여행자 이름을 차례대로 입력하세요.", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}

	//3. 도시 별 여행자들의 체류일 입력받기
	int travelDays[NUMCITY][NUMPEOPLE];
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("도시 %s에서 사람 %s가 보낸 일 수를 입력하세요: ", citynames[i], names[i]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}

	// 4. 도시 별 체류일 평균 구하기
	for (int i = 0; i < NUMCITY; i++) {
		int sum = 0;
		float average = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {
			sum += travelDays[i][j];
		}
		average = sum / (float)NUMPEOPLE; // average = sum / NUMPEOPLE;
		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2f\n", citynames[i], sum, average);
	}
	return 0;
}
