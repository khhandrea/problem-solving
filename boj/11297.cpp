#include <iostream>
#include <queue>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, x;
  std::priority_queue<int> pq;

  std::cin >> N;
  for (int n = 0; n < N; n++) {
    std::cin >> x;
    if (x > 0) {
      pq.push(x);
      continue;
    }
    if (pq.empty()) {
      std::cout << "0\n";
      continue;
    }
    std::cout << pq.top() << '\n';
    pq.pop();
  }

  return 0;
}
