// 01018번 체스판 다시 칠하기
#include <iostream>
#include <string>

using namespace std;

int main() {
    short N, M;
    short i, j, x, y;
    short current, max, min;
    string board_row;
    bool **board;

    // Input
    cin >> N >> M;
    cin.ignore();

    board = new bool*[N];
    for (i=0; i<N; i++) {
        board[i] = new bool[M];
    }

    for (i=0; i<N; i++) {
        getline(cin, board_row);
        for (j=0; j<M; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = (board_row[j] == 'W');
            }
            else {
                board[i][j] = (board_row[j] == 'B');
            }
        }
    }

    // Search and find max and min
    min = 65;
    max = -1;
    for (i=0; i<=N-8; i++) {
        for (j=0; j<=M-8; j++) {
            current = 0;
            for (y=i; y<i+8; y++) {
                for (x=j; x<j+8; x++) {
                    current += board[y][x];
                }
            }

            if (current < min) {
                min = current;
            }
            if (current > max) {
                max = current;
            }
        }
    }

    // Output
    if (max > (64 - min)) {
        cout << 64 - max << endl;
    }
    else {
        cout << min << endl;
    }

    for (i=0; i<8; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}