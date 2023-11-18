#include <stdio.h>

#define STUDENTS 5

// 학생 성적을 분류하는 함수
void classifyStudents(int* scores, char targetGrade) {
    printf("학생 성적 분류:\n");
    char grade = ' ';   // 학점을 저장할 변수 선언

    for (int i = 0; i < STUDENTS; i++) {   // STUDENTS 수 만큼 반복
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
            printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1, targetGrade);
        }
    }
}

int sumScores(int* scores) {   // scores는 int형 포인터로, 배열의 첫 번째 원소의 주소를 가리킴
    int sum = 0;

    for (int i = 0; i < STUDENTS; i++) {
        sum += *(scores + i);   // *(scores + i)는 i번째 학생의 성적을 의미
    }

    return sum;
}

double averageScores(int* scores) {   // scores는 int형 포인터로, 배열의 첫 번째 원소의 주소를 가리킴
    int sum = sumScores(scores);
    double average = (double)sum / (double)STUDENTS;
    return average;
}

void printRanks(int* scores) {   // scores는 int형 포인터로, 배열의 첫 번째 원소의 주소를 가리킴
    int ranks[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {   
        *(ranks + i) = 1;   // *(ranks + i)는 i번째 순위

        for (int j = 0; j < STUDENTS; j++) {
            if (*(scores + j) > *(scores + i)) {   // *(scores + j)와 *(scores + i)는 각각 j번째 학생과 i번째 학생의 성적
                (*(ranks + i))++;   // *(ranks + i)는 i번째 순위를 의미하며, 이를 증가시킴
            }
        }

        printf("%d 학생의 순위는 %d입니다.\n", i + 1, *(ranks + i));
    }
}

int main() {
    int scores[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {
        printf("학생 %d의 성적을 입력하세요: ", i + 1);
        scanf_s("%d", scores + i);   // scores + i는 i번째 학생의 성적을 가리킴
    }

    char ch = getchar();   // 버퍼에 남아있는 개행 문자 제거

    char target;
    printf("특정 점수 (A, B, C, D, F)를 입력하시오: ");
    scanf_s("%c", &target);   // 특정 점수 입력 받기

    classifyStudents(scores, target);

    int sum = sumScores(scores);
    double average = averageScores(scores);
    printf("학생들 점수의 총 합은 %d이고, 평균 값은 %lf입니다.\n", sum, average);   // 총합과 평균 출력

    printRanks(scores);   // 학생들의 순위 출력

    return 0;
}
