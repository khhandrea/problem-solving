#include <iostream>
#include <set>
#include <queue>

struct Pos {
  int x;
  int elapsed;

  bool operator<(Pos const &r) const {
    return (x < r.x);
  }

  bool operator==(Pos const &r) const {
    return (x == r.x);
  }
};

void push_bfs_queue(std::queue<Pos> *q, std::set<int> *visited, Pos pos) {
  if (pos.x <= 100001 &&
      visited->find(pos.x) == visited->end()) {
    q->push(pos);
  }
}

int main() {
  int N, K;
  Pos pos, next_pos;
  std::queue<Pos> q;
  std::set<int> visited;

  std::cin >> N >> K;

  // BFS
  pos.x = N;
  pos.elapsed = 0;
  q.push(pos);
  while (!q.empty()) {
    pos = q.front();
    q.pop();

    if (pos.x == K) {
      break;
    }

    visited.insert(pos.x);

    next_pos.elapsed = pos.elapsed + 1;

    next_pos.x = pos.x - 1;
    push_bfs_queue(&q, &visited, next_pos);

    next_pos.x = pos.x + 1;
    push_bfs_queue(&q, &visited, next_pos);

    next_pos.x = pos.x * 2;
    push_bfs_queue(&q, &visited, next_pos);
  }

  std::cout << pos.elapsed << '\n';

  return 0;
}
