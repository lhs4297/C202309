#include <stdio.h>
#include <stdlib.h> 

typedef struct Student { // 학생 정보를 저장하기 위한 구조체 선언
    char name[50]; // 학생 이름을 저장하는 문자열
    int score; // 학생의 점수를 저장하는 정수형 변수
} Student; // 구조체 별칭을 Student로 설정

void classifyStudents(Student* students, int studentCount, char targetGrade) { // 학생들의 성적을 분류하는 함수
    printf("학생 성적 분류:");
    char grade = ' '; // 학점을 저장할 변수

    // 모든 학생에 대해
    for (int i = 0; i < studentCount; i++) {
        // 점수에 따라 학점을 결정
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

        // 목표 학점과 같은 학생이 있다면 출력
        if (targetGrade == grade) {
            printf("%s 학생은 %c 점수를 받았습니다.", students[i].name, targetGrade);
        }
    }
}

int sumScores(Student* students, int studentCount) { // 학생들의 성적 합계를 계산하는 함수
    int sum = 0; // 합계를 저장할 변수

    // 모든 학생에 대해
    for (int i = 0; i < studentCount; i++) {
        sum += students[i].score; // 점수를 합계에 더함
    }

    return sum; // 합계를 반환
}

double averageScores(Student* students, int studentCount) { // 학생들의 성적 평균을 계산하는 함수
    int sum = sumScores(students, studentCount); // 학생들의 성적 합계를 계산
    double average = (double)sum / (double)studentCount; // 평균을 계산
    return average; // 평균을 반환
}

void printRanks(Student* students, int studentCount) { // 학생들의 순위를 출력하는 함수
    int* ranks = (int*)malloc(sizeof(int) * studentCount); // 순위를 저장할 동적 배열을 생성

    // 모든 학생에 대해
    for (int i = 0; i < studentCount; i++) {
        ranks[i] = 1; // 초기 순위를 1로 설정

        // 모든 학생에 대해
        for (int j = 0; j < studentCount; j++) {
            // 다른 학생의 점수가 더 높다면 순위를 증가
            if (students[j].score > students[i].score) {
                ranks[i]++;
            }
        }

        printf("%s 학생의 순위는 %d입니다.", students[i].name, ranks[i]); // 순위를 출력
    }

    free(ranks); // 순위 배열의 메모리를 해제
}

int main() {
    int studentCount; // 학생 수를 저장할 변수
    printf("학생 수를 입력하세요: ");
    scanf_s("%d", &studentCount); // 학생 수를 입력받음

    Student* students = (Student*)malloc(sizeof(Student) * studentCount); // 학생 정보를 저장할 동적 배열을 생성

    // 모든 학생에 대해
    for (int i = 0; i < studentCount; i++) {
        printf("학생 %d의 이름과 성적을 입력하세요: ", i + 1);
        scanf_s("%s %d", students[i].name, &(students[i].score)); // 이름과 성적을 입력받음
    }

    char ch = getchar(); // 버퍼를 비움

    char target; // 목표 학점을 저장할 변수
    printf("특정 점수 (A, B, C, D, F)를 입력하시오: ");
    scanf_s("%c", &target); // 목표 학점을 입력받음

    classifyStudents(students, studentCount, target); // 성적을 분류하고 출력

    int sum = sumScores(students, studentCount); // 성적 합계를 계산
    double average = averageScores(students, studentCount); // 성적 평균을 계산
    printf("학생들 점수의 총 합은 %d이고, 평균 값은 %lf입니다.", sum, average); // 성적 합계와 평균을 출력

    printRanks(students, studentCount); // 순위를 출력

    free(students); // 학생 정보 배열의 메모리를 해제

    return 0; // 프로그램 종료
}
