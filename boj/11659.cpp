#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M, i, j, num;
  int *sums;

  std::cin >> N >> M;
  sums = new int[N + 1];
  sums[0] = 0;
  for (int n = 1; n <= N; n++) {
    std::cin >> num;
    sums[n] = sums[n - 1] + num;
  }

  for (int m = 0; m < M; m++) {
    std::cin >> i >> j;
    std::cout << sums[j] - sums[i - 1] << '\n';
  }

  return 0;
}
