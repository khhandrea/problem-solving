#include <iostream>
#include <stack>

struct Tuple {
    short index;
    short height;
};

int get_max_rect(short **matrix, short N, short M);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    short N, M, n, m;
    short **matrix;
    int max_rect;

    while (true) {
        std::cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        // Create matrix
        matrix = new short*[N];
        for (n = 0; n < N; n++) {
            matrix[n] = new short[M];
        }

        for (n = 0; n < N; n++) {
            for (m = 0; m < M; m++) {
                std::cin >> matrix[n][m];
            }
        }

        max_rect = get_max_rect(matrix, N, M);
        std::cout << max_rect << '\n';

        // Delete matrix
        for (n = 0; n < N; n++) {
            delete matrix[n];
        }
        delete matrix;
    }

    return 0;
}

int get_max_rect(short **matrix, short N, short M) {
    int n, m, area, max_area = 0;
    std::stack<Tuple> stack;
    Tuple top;

    for (n = 0; n < N; n++) {
        for (m = 0; m < M; m++) {
            if (n != 0 && matrix[n][m] != 0) {
                matrix[n][m] = matrix[n - 1][m] + 1;
            }

            while (!stack.empty() && stack.top().height > matrix[n][m]) {
                top = stack.top();
                stack.pop();

                area = m - (stack.empty() ? 0 : stack.top().index + 1);
                area *= top.height;
                max_area = (area > max_area ? area : max_area);
            }

            top.index = m;
            top.height = matrix[n][m];
            stack.push(top);
        }

        while (!stack.empty()) {
            top = stack.top();
            stack.pop();

            area = M - (stack.empty() ? 0 : stack.top().index + 1);
            area *= top.height;
            max_area = (area > max_area ? area : max_area);
        }
    }

    return max_area;
}
