#include <stdio.h>

int main(void)
{
	// for ( 선언; 조건; 증감 ) { 수행할 문장 }
	// while (조건) { 수행할 문장 ( 증감 포함 ) }
	int i = 0;   // 선언
	while (i < 10) {   // 조건
		if (i % 2 == 0) {
			i++;   // 만약 i를 2로 나눈 나머지가 0이라면 ( 짝수라면 ) i를 1올리고 계속한다
			continue;
		}
		printf("%d Hello World! \n", i);   // 짝수에서 +1했으니 출력되는건 홀수
		i++;   // 프린트 후 i를 1 올린다
	}
	return 0;
}