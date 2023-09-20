#include <stdio.h>

int main() {
    int choice;   //choice를 int 타입으로 받겠다

    printf("1. 파일 저장\n");
    printf("2. 저장 없이 닫기\n");
    printf("3. 종료\n");

    scanf_s("%d", &choice);   // 사용자에게 입력받은 숫자를 choice에 담는다

    if (choice == 1) {   // 만약 choice가 1이라면 실행
        printf("파일을 저장합니다.\n");
    }
    else if (choice == 2) {   // 위의 if문이 거짓이고 choice가 2라면 실행해라
        printf("저장없이 닫습니다.\n");
    }
    else if (choice == 3) {   
        printf("종료합니다.\n");
    }
    else {   // 위의 if문들이 모두 거짓이라면 이 문장을 실행해라
        printf("잘못 입력하셨습니다.\n");
    }

    return 0;
}
