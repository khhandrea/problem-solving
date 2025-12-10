#include <stdio.h>

int main() {
    const char r = 31;
    const int M = 1234567891;
    char L, input;
    long scale = 1, result = 0;

    scanf("%hhd", &L);
    getchar();
    for(char i=0; i<L; i++) {
        input = getchar() - 'a' + 1;
        result = (result + scale * input) % M;
        scale = (scale * r) % M;
    }
    printf("%d\n", result);

    return 0;
}