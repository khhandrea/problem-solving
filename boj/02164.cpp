#include <iostream>
#include <queue>

int main() {
  bool is_odd = true;
  int N;
  std::queue<int> dq;

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    dq.push(i);
  }

  while (dq.size() > 1) {
    if (is_odd) {
      dq.pop();
    }
    else {
      dq.push(dq.front());
      dq.pop();
    }
    is_odd = !is_odd;
  }

  std::cout << dq.back() << '\n';
}
