#include <cmath>
#include <iostream>
#include <queue>

struct Compare {
  bool operator()(int &l, int &r) const {
    if (std::abs(l) == std::abs(r)) {
      return (l > r);
    }
    return abs(l) > abs(r);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, x;
  std::priority_queue<int, std::vector<int>, Compare> pq;

  std::cin >> N;
  for (int n = 0; n < N; n++) {
    std::cin >> x;
    if (x != 0) {
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
