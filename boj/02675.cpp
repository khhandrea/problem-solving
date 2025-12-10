// 02675번 문자열 반복
#include <stdio.h>

int main() {
    char T, R, i, j;
    char *iter;
    char string[20];

    scanf("%hhd", &T);

    for (i=0; i<T; i++) {
        scanf("%hhd %s", &R, string);

        for (iter=string; *iter!=0; iter++) {
            for (j=0; j<R; j++) {
                printf("%c", *iter);
            }
        }
        printf("\n");
    }

    return 0;
}