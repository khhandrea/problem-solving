#include <iostream>

int min(int a, int b) {
  return (a > b ? b : a);
}

int main() {
  int N;
  int *square_sums;

  std::cin >> N;
  square_sums = new int[N + 1];

  for (int n = 1; n <= N; n++) {
    square_sums[n] = n;
    for (int i = 1; i * i <= n; i++) {
      square_sums[n] = min(square_sums[n], square_sums[n - i * i] + 1);
    }
  }

  std::cout << square_sums[N] << '\n';

  return 0;
}
