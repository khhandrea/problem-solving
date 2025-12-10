// 12720번 숫자의 합
#include <stdio.h>

int main() {
    char N, c, i;
    short result = 0;

    scanf("%hhd ", &N);

    for (i=0; i<N; i++) {
        result += getchar() - '0';
    }

    printf("%hd\n", result);

    return 0;
}