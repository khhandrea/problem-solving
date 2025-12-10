#include <stdio.h>

bool is_pythagorean(short a, short b, short c) {
    bool result = (a * a + b * b == c * c);
    return result;
}

int main() {
    short a, b, c, max = 0;
    bool result;

    while (true) {
        scanf("%hd %hd %hd", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        if (a >= b && a >= c) result = is_pythagorean(b, c, a);
        else if (b > a && b >= c) result = is_pythagorean(a, c, b);
        else result = is_pythagorean(a, b, c);

        if (result) {
            printf("right\n");
        }
        else {
            printf("wrong\n");
        }
    }

    return 0;
}