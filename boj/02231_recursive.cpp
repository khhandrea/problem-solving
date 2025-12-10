#include <iostream>
#include <math.h>

using std::cin, std::cout, std::pow;

unsigned int get_digit(unsigned int N);
unsigned int find_decomp_sum(unsigned int N, unsigned int digit);

int main() {
    unsigned int N, result;

    cin >> N;
    result = find_decomp_sum(N, get_digit(N));
    if (result == -1) {
        result = 0;
    }
    cout << result << '\n';

    return 0;
}

unsigned int get_digit(unsigned int N) {
    int digit = 0;

    do {
        N /= 10;
        digit += 1;
    } while (N != 0);

    return digit;
}

unsigned int find_decomp_sum(unsigned int N, unsigned int digit) {
    unsigned int i, next_N, find, sub_max = 0;

    if (digit == 1) {
        if (N % 2 == 0) {
            return N / 2;
        }
        else {
            return -1;
        }
    }

    for (i=0; i<digit-1; i++) {
        sub_max *= 10;
        sub_max += 1;
    }
    sub_max = 9 * (digit + sub_max - 1);

    for (i=0; i<10; i++) {
        next_N = N - (i * pow(10, digit - 1)) - i;
        if (next_N <= sub_max) {
            find = find_decomp_sum(next_N, digit - 1);
            if (find != -1) {
                return (i * pow(10, digit - 1)) + find;
            }
        }
    }
    return -1;
}