#include <stdio.h>

int main() {
    int T, N, H, W;
    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        scanf("%d %d %d", &H, &W, &N);
        printf("%d%02d\n", (N % H == 0) ? H : (N % H), ((N - 1) / H) + 1);
    }
    return 0;
}