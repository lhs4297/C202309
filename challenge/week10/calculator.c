#include <stdio.h>

void summation(double* a, double* b, double* result) {
    *result = *a + *b;   // �� ���� ���� ����Ͽ� result�� ����
}

void subtraction(double* a, double* b, double* result) {
    *result = *a - *b;   // �� ���� ���� ����Ͽ� result�� ����
}

void multiplication(double* a, double* b, double* result) {
    *result = *a * *b;   // �� ���� ���� ����Ͽ� result�� ����
}

void division(double* a, double* b, double* result) {
    if (*b == 0) {   // 0���� ������ ��츦 Ȯ��
        printf("0���� ���� �� �����ϴ�.");
        return;
    }
    *result = *a / *b;   // �� ���� �������� ����Ͽ� result�� ����
}

int main() {
    double a, b, result;
    printf("�� ������ �Է��ϼ���: ");
    scanf_s("%lf %lf", &a, &b);   // ����ڷκ��� �� ���� �Է¹޾Ƽ� ���� a�� b�� ����. �� �� &�� ����Ͽ� ������ �ּҸ� ����

    summation(&a, &b, &result);   // ���� a, b, result�� �ּҸ� �����Ͽ� �Լ� ������ �ش� ������ ���� ������ �� �ְ� ��
    printf("%.0f + %.0f = %.02f\n", a, b, result);

    subtraction(&a, &b, &result);
    printf("%.0f - %.0f = %.02f\n", a, b, result);

    multiplication(&a, &b, &result);
    printf("%.0f * %.0f = %.02f\n", a, b, result);

    division(&a, &b, &result);
    printf("%.0f / %.0f = %.2lf", a, b, result);

    return 0;
}
