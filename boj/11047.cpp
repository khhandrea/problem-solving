#include <iostream>

int main() {
  short N;
  int K, result = 0;
  int *coins;

  std::cin >> N >> K;
  coins = new int[N];
  for (short i = 0; i < N; i++) {
    std::cin >> coins[i];
  }

  for (short i = N - 1; i >= 0; i--) {
    result += K / coins[i];
    K %= coins[i];
  }

  std::cout << result << '\n';

  return 0;
}
