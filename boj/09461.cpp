#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short T, N, cur = 4;
  std::vector<long long> P = {0, 1, 1, 1, 2};

  std::cin >> T;
  for (short t = 0; t < T; t++) {
    std::cin >> N;
    for (; cur <= N; cur++) {
      P.push_back(P[cur] + P[cur - 4]);
    }
    std::cout << P[N] << '\n';
  }

  return 0;
}
