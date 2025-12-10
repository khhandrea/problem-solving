// 10952번 A+B - 5
#include <stdio.h>

int main() {
    char A, B;

    while (true) {
        scanf("%hhd %hhd", &A, &B);

        if (A == 0 && B == 0) break;

        printf("%d\n", A + B);
    }

    return 0;
}