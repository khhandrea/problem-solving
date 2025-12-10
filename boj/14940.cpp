#include <iostream>
#include <queue>

struct Point {
  char type;
  int distance;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short n, m, row, col;
  short drow[4] = {0, 0, -1, 1};
  short dcol[4] = {-1, 1, 0, 0};
  Point **map;
  std::queue<std::pair<short, short> > q;

  std::cin >> n >> m;
  std::cin.get();
  map = new Point*[n];
  for (short i = 0; i < n; i++) {
    map[i] = new Point[m];
    for (short j = 0; j < m; j++) {
      map[i][j].type = std::cin.get();
      std::cin.get();

      if (map[i][j].type == '0') {
        map[i][j].distance = 0;
      }
      else if (map[i][j].type == '1') {
        map[i][j].distance = -1;
      }
      else {
        map[i][j].distance = 0;
        q.push(std::make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    row = q.front().first;
    col = q.front().second;
    q.pop();

    for (short i = 0; i < 4; i++) {
      if (row + drow[i] < 0 || row + drow[i] >= n ||
          col + dcol[i] < 0 || col + dcol[i] >= m ||
          map[row + drow[i]][col + dcol[i]].distance != -1) {
        continue;
      }

      q.push(std::make_pair(row + drow[i], col + dcol[i]));
      map[row + drow[i]][col + dcol[i]].distance = map[row][col].distance + 1;
    }
  }

  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      std::cout << map[i][j].distance << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
