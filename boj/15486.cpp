#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short *T, *P;
  int N, max_profit;
  int *max_profits;

  std::cin >> N;
  T = new short[N];
  P = new short[N];
  max_profits = new int[N];
  for (int n = 0; n < N; n++) {
    std::cin >> T[n] >> P[n];
  }

  max_profit = 0;
  for (int n = 0; n < N; n++) {
    if (n + T[n] > N) {
      continue;
    }

    max_profits[n] = P[n];
    for (int i = 0; i < n; i++) {
      if (i + T[i] <= n && P[n] + max_profits[i] > max_profits[n]) {
        max_profits[n] = P[n] + max_profits[i];
      }
    }

    if (max_profits[n] > max_profit) {
      max_profit = max_profits[n];
    }
  }

  std::cout << max_profit << '\n';

  return 0;
}
