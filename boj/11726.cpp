#include <iostream>

int main() {
  short n, prevprev, prev = 1, cur = 1;

  std::cin >> n;

  for (short i = 0; i < n - 1; i++) {
    prevprev = prev;
    prev = cur;
    cur = (prevprev + prev) % 10007;
  }
  std::cout << cur << '\n';

  return 0;
}
