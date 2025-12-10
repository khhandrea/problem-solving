// 27866번 문자와 문자열
#include <stdio.h>

int main() {
    short i;
    char string[1000];

    scanf("%s", string);
    scanf("%hd", &i);
    printf("%c\n", string[i - 1]);

    return 0;
}