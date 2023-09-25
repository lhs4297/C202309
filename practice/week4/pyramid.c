#include <stdio.h>

int main() {
    int floor;   // floor를 int type으로 받겠다

    printf("몇 층을 쌓겠습니까? (5~100) ");
    scanf_s("%d", &floor);

    for (int i = 0; i < floor; i++) {   // scanf_s로 받은 floor값 만큼 반복되게 한다. --> 층 수를 담당함
        for (int j = 0; j < floor - i - 1; j++) {   // floor값 -i -1 값 만큼 출력할꺼다  --> S의 출력을 담당함 --> 피라미드 모양을 만들어줌
            printf("S");
        }

        for (int k = 0; k < i * 2 + 1; k++) {   // *모양이 1,3,5,7....으로 출력되게 만들어줌
            printf("*");
        }

        printf("\n");   // 한층 출력하고 층을 바꾸어줌
    }

    return 0;
}
