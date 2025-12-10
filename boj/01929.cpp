// 01929번 소수 구하기
#include <stdio.h>

using namespace std;

int main() {
    int M, N, i, j;
    int *sieve;

    scanf("%d %d", &M, &N);
    sieve = new int[N + 1];

    sieve[1] = 0;
    for (i=2; i<=N; i++) {
        sieve[i] = i;
    }

    for (i=2; i*2<=N; i++) {
        if (sieve[i] == 0) {
            continue;
        }
        for (j=i*2; j<=N; j+=i) {
            sieve[j] = 0;
        }
    }

    for (i=M; i<=N; i++) {
        if (sieve[i] != 0) {
            printf("%d\n", sieve[i]);
        }
    }

    delete[] sieve;

    return 0;
}