#include <iostream>

int main() {
  int T, result[15];
  short k, n, t, floor, ho;

  std::cin >> T;
  for (t = 0; t < T; t++) {
    std::cin >> k >> n;
    for (ho = 1; ho <= n; ho++) {
      result[ho] = ho;
    }

    for (floor = 1; floor <= k; floor++) {
      for (ho = 2; ho <= n; ho++) {
        result[ho] += result[ho - 1];
      }
    }

    std::cout << result[n] << '\n';
  }

  return 0;
}
