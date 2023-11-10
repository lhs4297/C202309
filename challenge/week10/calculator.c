#include <stdio.h>

void summation(double* a, double* b, double* result) {
    *result = *a + *b;   // 두 값의 합을 계산하여 result에 저장
}

void subtraction(double* a, double* b, double* result) {
    *result = *a - *b;   // 두 값의 차를 계산하여 result에 저장
}

void multiplication(double* a, double* b, double* result) {
    *result = *a * *b;   // 두 값의 곱을 계산하여 result에 저장
}

void division(double* a, double* b, double* result) {
    if (*b == 0) {   // 0으로 나누는 경우를 확인
        printf("0으로 나눌 수 없습니다.");
        return;
    }
    *result = *a / *b;   // 두 값의 나눗셈을 계산하여 result에 저장
}

int main() {
    double a, b, result;
    printf("두 정수를 입력하세요: ");
    scanf_s("%lf %lf", &a, &b);   // 사용자로부터 두 수를 입력받아서 변수 a와 b에 저장. 이 때 &를 사용하여 변수의 주소를 전달

    summation(&a, &b, &result);   // 변수 a, b, result의 주소를 전달하여 함수 내에서 해당 변수를 직접 수정할 수 있게 함
    printf("%.0f + %.0f = %.02f\n", a, b, result);

    subtraction(&a, &b, &result);
    printf("%.0f - %.0f = %.02f\n", a, b, result);

    multiplication(&a, &b, &result);
    printf("%.0f * %.0f = %.02f\n", a, b, result);

    division(&a, &b, &result);
    printf("%.0f / %.0f = %.2lf", a, b, result);

    return 0;
}
