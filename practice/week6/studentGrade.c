#include <stdio.h>
#define STUDENTS 5

// 학생 성적 분류하는 함수
void classifyStudents(int scores[], char targetGrade) {
	printf("학생 성적 분류:\n");   // 학생 성적 분류를 출력하는 부분
	char grade = ' ';   // 학점을 저장할 변수
	for (int i = 0; i < STUDENTS; i++) {
		if (scores[i] >= 90) {   // 90 이상이면 A 학점
			grade = 'A';
		}
		else if (scores[i] >= 80) {   // 80 이상이면 B 학점
			grade = 'B';
		}
		else if (scores[i] >= 70) {   // 70 이상이면 C 학점
			grade = 'C';
		}
		else if (scores[i] >= 60) {   // 60 이상이면 D 학점
			grade = 'D';
		}
		else {   // 60 미만이면 F 학점
			grade = 'F';
		}
		if (targetGrade == grade) {   // 목표 학점과 학생의 학점이 일치하는 경우
			printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1, targetGrade);
		}
	}
}

int main() {
	int scores[STUDENTS];   // 학생들의 성적을 저장할 배열

	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입력하세요: ", i + 1);
		scanf_s("%d", &scores[i]);   // 학생들의 성적을 입력받음
	}

	char ch = getchar();   // 버퍼에 남아있는 개행 문자를 제거하기 위해 사용

	char target;
	printf("특정 점수 (A, B, C, D, F)를 입력하시오: ");
	scanf_s("%c", &target, 1);   // 특정 점수(A, B, C, D, F)를 입력받음

	classifyStudents(scores, target);   // classifyStudents 함수를 호출하여 학생 성적을 분류

	return 0;
}
