// 01152번 단어의 개수
#include <stdio.h>

int main() {
    char buffer[2] = {' ', ' '};
    int result = 0;

    while ((buffer[0]=getchar()) != '\n') {
        if (buffer[0] != ' ' && buffer[1] == ' ') {
            result += 1;
        }
        buffer[1] = buffer[0];
    }

    printf("%d\n", result);

    return 0;
}