#include <stdio.h>

int main() {
    int floor;

    printf("¸î ÃþÀ» ½×°Ú½À´Ï±î? (5~100) ");
    scanf_s("%d", &floor);

    for (int i = floor; i >= 1; --i) {
        for (int j = 0; j <= floor - i -1; ++j) {
            printf("S");
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
