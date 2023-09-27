#include <stdio.h>

int main(void)
{
	// for ( 선언; 조건; 증감 ) { 수행할 문장 }
	// 선언 do { 수행할 문장 } 프린트( 증감 ) while( 조건 ) 

    int i = 0;   // 선언

    do {   // 일단 실행
        // 수행할 문장
        if (i % 2 == 0) {   // i를 2로나눈 나머지가 0이라면 ( 짝수라면 )
            i++;   // i 를 1증가하고
            continue;   // 아래 코드를 계속한다
        }
        printf("%d Hello World!\n", i++);   // i를 출력 ( i는 짝수에서 +1했으니까 홀수 ) 후 1증가
    } while (i < 10);  // 최종 i가 10미만일때까지 반복, 아니면 반복x

	return 0;
}