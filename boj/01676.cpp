// 01676번 팩토리얼 0의 개수
#include <stdio.h>

int main() {
    unsigned char count5 = 0;
    short N, i;

    scanf("%hd", &N);
    
    for (i=5; i<=N; i*=5) {
        count5 += N / i;
    }

    printf("%hhd\n", count5);

    return 0;
}