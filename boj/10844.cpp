// 10844번 쉬운 계단 수
#include <stdio.h>

int main() {
    char N, i, j;
    int **table;
    int result = 0;

    scanf("%hhd", &N);

    // Initialize
    table = new int*[N];
    for (i=0; i<N; i++) {
        table[i] = new int[9]();
    }

    for (j=1; j<10; j++) {
        table[0][j] = 1;
    }

    // DP
    for (i=1; i<N; i++) {
        for (j=0; j<10; j++) {
            table[i][j] = 0;
            if (j != 0) {
                table[i][j] += table[i - 1][j - 1];
            }
            if (j != 9) {
                table[i][j] += table[i - 1][j + 1];
            }
            table[i][j] %= 1000000000;
        }
    }
    for(j=0; j<10; j++) {
        result += table[N - 1][j];
        result %= 1000000000;
    }

    printf("%d\n", result);

    for (i=0; i<N; i++) {
        delete[] table[i];
    }
    delete[] table;

    return 0;
}

//   0 1 2 3 4 5 6 7 8 9: 맨 끝자리
// 1 0 1 1 1 1 1 1 1 1 1
// 2 1 1 2 2 2 2 2 2 2 1
// 3 1 2 4 8 10 
// 자릿수