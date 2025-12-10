#include <iostream>
#include <queue>

int main() {
  short N, K;
  std::queue<short> q;
  std::cin >> N >> K;
  for (short i = 1; i <= N; i++) {
    q.push(i);
  }

  std::cout << '<';
  for (short i = 0; i < N - 1; i++) {
    for (short j = 0; j < K - 1; j++) {
      q.push(q.front());
      q.pop();
    }
    std::cout << q.front() << ", ";
    q.pop();
  }
  std::cout << q.front() << ">\n";
}
