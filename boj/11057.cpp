// 11057번 오르막 수
#include <stdio.h>

int main() {
    short N, i, j, result = 0;
    short table[10];

    scanf("%hd", &N);

    // Initialize
    for (j=0; j<10; j++) {
        table[j] = 1;
    }

    // DP
    for (i=1; i<N; i++) {
        for (j=0; j<10; j++) {
            if (j > 0) {
                table[j] += table[j - 1];
            }
            table[j] %= 10007;
        }
    }
    for (j=0; j<10; j++) {
        result += table[j];
        result %= 10007;
    }

    printf("%hd\n", result);
    
    return 0;
}

//   9  8  7  6  5  4  3  2  1  0
// 1 1  1  1  1  1  1  1  1  1  1
// 2 1  2  3  4  5  6  7  8  9 10
// 3 1  3  6 10 15 21 28 36 45 55