// 01330번 두 수 비교하기
#include <stdio.h>

int main() {
    short A, B;

    scanf("%hd %hd", &A, &B);

    if (A < B)
        printf("<\n");
    else if (A == B)
        printf("==\n");
    else 
        printf(">\n");

    return 0;
}