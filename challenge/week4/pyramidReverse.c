#include <stdio.h>

int main() {
    int floor;

    printf("몇 층을 쌓겠습니까? (5~100) ");
    scanf_s("%d", &floor);   // 기존 피라미드 쌓기와 동일

    for (int i = floor; i >= 1; --i) {   // 피라미드와 반대로 i가 0에서 시작이 아닌 floor에서 시작 and 1씩 감소
        for (int j = 0; j <= floor - i -1; ++j) {   //floor값 -i -1 값 만큼 출력할꺼다  --> S의 출력을 담당함 --> 피라미드 모양을 만들어줌
            printf("S");
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {   // *모양이 1,3,5,7... 으로 쌓이게 함
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
