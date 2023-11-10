#include <stdio.h>

#define STUDENTS 5   // 학생 수, 과목 수, 문자열 길이를 정의
#define SUBJECTS 3
#define CHARNUM 20

void printStudentResults(char studentNames[][CHARNUM], double studentScores[][SUBJECTS]) {   // 학생 별 평균 점수를 계산하고 출력하는 함수
    printf("학생 별 성적은 다음과 같습니다.\n");
    for (int i = 0; i < STUDENTS; i++) {
        double sum = 0.0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += studentScores[i][j];   // 각 학생의 점수 합계를 계산
        }
        printf("\t%s의 평균 점수: %.2f\n", studentNames[i], sum / SUBJECTS);   // 학생의 평균 점수를 출력
    }
    printf("----------------------------\n");
}

void printSubjectResults(char subjectNames[][CHARNUM], double studentScores[][SUBJECTS]) {   // 과목 별 평균 점수를 계산하고 출력하는 함수
    printf("과목 별 평균 점수는 아래와 같습니다.\n");
    for (int i = 0; i < SUBJECTS; i++) {
        double sum = 0.0;
        for (int j = 0; j < STUDENTS; j++) {
            sum += studentScores[j][i];   // 각 과목의 점수 합계를 계산
        }
        printf("\t%s의 평균 점수: %.2f 입니다.\n", subjectNames[i], sum / STUDENTS);   // 과목의 평균 점수를 출력
    }
    printf("프로그램을 종료합니다.\n");
}

int main() {
    char subjectNames[SUBJECTS][CHARNUM] = { "퀴즈", "중간고사", "기말고사" };   // 과목 이름을 정의
    char studentNames[STUDENTS][CHARNUM];   // 학생 이름을 저장할 배열 선언
    double studentScores[STUDENTS][SUBJECTS];   // 학생 점수를 저장할 배열 선언

    printf("학생 %d명의 이름의 입력을 시작합니다.\n", STUDENTS);

    for (int i = 0; i < STUDENTS; i++) {
        printf("\t%d번째 학생의 이름을 입력하세요: ", i + 1);
        fgets(studentNames[i], CHARNUM, stdin);   // 학생 이름 입력 받음
        studentNames[i][strcspn(studentNames[i], "\n")] = 0;   // 개행 문자를 null 문자로 변경
    }
    printf("학생 이름이 모두 입력되었습니다.");
    printf("\n입력된 학생 이름은 다음과 같습니다.\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("%s,", studentNames[i]);   // 입력된 학생 이름 출력
    }
    printf("\n----------------------------\n");

    printf("각 학생의 퀴즈, 중간고사, 기말고사 점수를 차례대로 입력하세요\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("\t%s의 성적: ", studentNames[i]);
        for (int j = 0; j < SUBJECTS; j++) {
            scanf_s("%lf", &studentScores[i][j]);   // 학생 점수 입력 받음
        }
        getchar(); // 버퍼를 비우는 코드 추가
    }
    printf("학생들의 시험 점수가 모두 입력 되었습니다.\n");
    printf("----------------------------\n");

    printStudentResults(studentNames, studentScores);   // 학생 별 평균 점수 계산 및 출력하는 함수 호출
    printSubjectResults(subjectNames, studentScores);   // 과목 별 평균 점수 계산 및 출력하는 함수 호출

    return 0;
}
