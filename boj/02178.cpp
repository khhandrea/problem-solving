#include <iostream>
#include <set>
#include <queue>

struct Coord {
  short x;
  short y;
  short distance;

  bool operator==(const Coord &r) const {
    return (x == r.x && y == r.y);
  }

  bool operator<(const Coord &r) const {
    if (x != r.x) {
      return (x < r.x);
    }
    return (y < r.y);
  }
};

int main() {
  short N, M;
  char **maze;
  std::queue<Coord> q;
  std::set<Coord> visited;
  Coord next_coord, coord = {0, 0, 1};
  short dx[4] = {+1, -1, 0, 0};
  short dy[4] = {0, 0, +1, -1};
  bool found_target = false;

  // Input
  std::cin >> N >> M;

  maze = new char*[N];
  for (short i = 0; i < N; i++) {
    maze[i] = new char[M];
  }

  for (short i = 0; i < N; i++) {
    std::cin.get();
    for (short j = 0; j < M; j++) {
       std::cin.get(maze[i][j]);
    }
  }

  // BFS
  visited.insert(coord);
  q.push(coord);
  while (!found_target) {
    coord = q.front();
    q.pop();

    for (short i = 0; i < 4; i++) {
      next_coord.x = coord.x + dx[i];
      next_coord.y = coord.y + dy[i];
      next_coord.distance = coord.distance + 1;

      if (next_coord.x == M - 1 && next_coord.y == N - 1) {
        found_target = true;
        break;
      }

      if (next_coord.x < 0 || next_coord.x >= M ||
          next_coord.y < 0 || next_coord.y >= N ||
          visited.find(next_coord) != visited.end() ||
          maze[next_coord.y][next_coord.x] != '1') {
        continue;
      }

      visited.insert(next_coord);
      q.push(next_coord);
    }
  }

  std::cout << next_coord.distance << '\n';

  return 0;
}


