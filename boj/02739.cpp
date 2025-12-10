// 02739번 구구단
#include <stdio.h>

int main() {
    char N, i;

    scanf("%hhd", &N);

    for (i=1; i<10; i++) {
        printf("%hhd * %hhd = %d\n", N, i, N * i);
    }

    return 0;
}