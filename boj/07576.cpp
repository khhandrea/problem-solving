#include <iostream>
#include <queue>

struct Cell {
  short type;
  int day;
};

struct Coord {
  short row;
  short col;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short M, N, row, col;
  short drow[4] = {0, 0, -1, 1};
  short dcol[4] = {-1, 1, 0, 0};
  int max_day = 0;
  Cell **map;
  std::queue<Coord> bfs_q;

  // Input
  std::cin >> M >> N;
  map = new Cell*[N];
  for (short r = 0; r < N; r++) {
    map[r] = new Cell[M];
    for (short c = 0; c < M; c++) {
      std::cin >> map[r][c].type;

      if (map[r][c].type == 1) {
        map[r][c].day = 0;
        bfs_q.push({r, c});
        continue;
      }
      map[r][c].day = -1;
    }
  }

  // bfs
  while (!bfs_q.empty()) {
    row = bfs_q.front().row;
    col = bfs_q.front().col;
    bfs_q.pop();

    for (short i = 0; i < 4; i++) {
      if (row + drow[i] < 0 || row + drow[i] >= N ||
          col + dcol[i] < 0 || col + dcol[i] >= M ||
          map[row + drow[i]][col + dcol[i]].type != 0 ||
          map[row + drow[i]][col + dcol[i]].day != -1) {
        continue;
      }

      map[row + drow[i]][col + dcol[i]].day = map[row][col].day + 1;
      bfs_q.push({static_cast<short>(row + drow[i]), static_cast<short>(col + dcol[i])});
    }
  }

  // check result
  for (short r = 0; r < N && max_day != -1; r++) {
    for (short c = 0; c < M; c++) {
      if (map[r][c].type == 0 && map[r][c].day == -1) {
        max_day = -1;
        break;
      }

      if (map[r][c].type == 0 && map[r][c].day > max_day) {
        max_day = map[r][c].day;
      }
    }
  }

  std::cout << max_day << '\n';

  return 0;
}
