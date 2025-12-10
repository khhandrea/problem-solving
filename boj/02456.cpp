#include <stdio.h>

int main() {
    char input;
    short sum = 0;

    sum = 0;
    for(char i=0; i<5; i++) {
        scanf("%hhd", &input);
        sum += input * input;
    }
    printf("%hhd\n", sum % 10);

    return 0;
}