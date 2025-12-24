#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int dfs(int y, int x, const vector<string>& map, vector<vector<int>>& visited) {
    visited[y][x] = 1;

    int num_person = (map[y][x] == 'P' ? 1 : 0);
    for (int i = 0; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        // Check valid coordinate
        if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
            continue;
        }

        // Check visited or wall
        if (visited[next_y][next_x] || map[next_y][next_x] == 'X') {
            continue;
        }

        num_person += dfs(next_y, next_x, map, visited);
    }

    return num_person;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<string> map(N);
    int start_y, start_x;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'I') {
                start_y = i;
                start_x = j;
            }
        }
    }
    
    vector<vector<int>> visited(N, vector<int>(M, 0));

    int num_person = dfs(start_y, start_x, map, visited);

    if (num_person == 0) {
        cout << "TT\n";
    }
    else {
        cout << num_person << '\n';
    }

    return 0;
 }