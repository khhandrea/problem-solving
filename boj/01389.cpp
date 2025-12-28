#include <algorithm>
#include <iostream>

#define INT_INF 1000000000 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input first line
    int N, M;
    cin >> N >> M;
    int distance[101][101] = {};

    // Initialize distances to infinity
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            distance[i][j] = (i == j ? 0 : INT_INF);
        }
    }

    // Input remaining lines
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        distance[A][B] = 1;
        distance[B][A] = 1;
    }

    // Floyd-Warshall
    for (int m = 1; m <= N; m++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                distance[a][b] = min(distance[a][b], distance[a][m] + distance[m][b]);
            }
        }
    }

    // Maximum step
    int min_step = INT_INF;
    int min_index;
    for (int i = 1; i <= N; i++) {
        int sum_step = 0;
        for (int j = 1; j <= N; j++) {
            sum_step += distance[i][j];
        }

        if (sum_step < min_step) {
            min_step = sum_step;
            min_index = i;
        }
    }

    // Output
    cout << min_index << '\n';

    return 0;
}