#include <iostream>
#include <queue>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, value;
  std::priority_queue<int> pq;

  std::cin >> N;
  for (int n = 0; n < N; n++) {
    std::cin >> value;
    if (value > 0) {
      pq.push(-value);
    }
    else if (pq.size() > 0) {
      std::cout << -pq.top() << '\n';
      pq.pop();
    }
    else {
      std::cout << "0\n";
    }
  }

  return 0;
}
