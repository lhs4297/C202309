#include <stdio.h>

int main() {
	int num = 0;
	printf("숫자를 입력하시오: ");
	scanf_s("%d", &num);
	
    if (num == 0) {   // 만약 num이 0이라면 실행
        printf("zero");
    }
    else if (num == 1) {   // 위의 문장이 아니면서 num이 1 이라면 실행해라
        printf("one");
    }
    else if (num == 2) {   // 위의 문장이 아니면서 num이 2 이라면 실행해라
        printf("two");
    }
    else {   // 위의 if문들이 모두 거짓이라면 이 문장을 실행해라
        printf("not 0 ~ 2");
    }

    return 0;
}