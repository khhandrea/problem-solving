// 02562번 최댓값
#include <stdio.h>

int main() {
    char i, buffer, max = 0, argmax;

    for (i=0; i<9; i++) {
        scanf("%hhd", &buffer);
        if (buffer > max) {
            max = buffer;
            argmax = i + 1;
        }
    }

    printf("%hhd\n", max);
    printf("%hhd\n", argmax);

    return 0;
}