#include <iostream>

int main() {
    char score, max_score = 0;
    short N;
    int sum = 0;
    float mean;

    scanf("%hd", &N);
    for (short i=0; i<N; i++) {
        scanf("%hhd", &score);
        if (max_score < score) {
            max_score = score;
        }
        sum += score;
    }
    mean = ((float)sum / N)/ max_score * 100;
    printf("%.6f\n", mean);
    return 0;
}