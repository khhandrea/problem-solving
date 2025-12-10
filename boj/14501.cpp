#include <iostream>

int main() {
  short N, max_profit;
  short *T, *P, *max_profits;

  std::cin >> N;
  T = new short[N];
  P = new short[N];
  max_profits = new short[N];
  for (short n = 0; n < N; n++) {
    std::cin >> T[n] >> P[n];
  }

  max_profit = 0;
  for (short n = 0; n < N; n++) {
    if (n + T[n] > N) {
      continue;
    }

    max_profits[n] = P[n];
    for (short i = 0; i < n; i++) {
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
