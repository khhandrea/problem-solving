#include <algorithm>
#include <iostream>
#include <queue>

struct Document {
  short index, priority;

  bool operator<(const Document &r) const {
    return (priority < r.priority);
  }
};

int main() {
  short T, N, M, order;
  std::queue<Document> q;
  std::priority_queue<Document> pq;
  Document item;

  std::cin >> T;

  for (short t = 0; t < T; t++) {
    std::cin >> N >> M;
    for (short i = 0; i < N; i++) {
      item.index = i;
      std::cin >> item.priority;
      q.push(item);
      pq.push(item);
    }

    order = 1;
    while (true) {
      if (q.front().priority != pq.top().priority) {
        q.push(q.front());
      }
      else {
        if (q.front().index == M) {
          std::cout << order << '\n';
          break;
        }

        pq.pop();
        order++;
      }
      q.pop();
    }

    while (!q.empty()) q.pop();
    while (!pq.empty()) pq.pop();
  }

  return 0;
}
