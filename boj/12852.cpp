#include <iostream>

int main() {
  int N, i = 0;
  int *dp;

  std::cin >> N;

  dp = new int[N + 1];
  for (int i = 1; i <= N; i++) {
    dp[i] = i - 1;
  }

  for (i = 1; i < N; i++) {
    if (dp[i] + 1 < dp[i + 1]) {
      dp[i + 1] = dp[i] + 1;
    }
    if (i * 2 <= N && dp[i] + 1 < dp[i * 2]) {
      dp[i * 2] = dp[i] + 1;
    }
    if (i * 3 <= N && dp[i] + 1 < dp[i * 3]) {
      dp[i * 3] = dp[i] + 1;
    }
  }

  std::cout << dp[N] << '\n';

  i = N;
  while (i > 1) {
    std::cout << i << ' ';
    if (dp[i - 1] == dp[i] - 1) {
      i -= 1;
    }
    else if (i % 2 == 0 && dp[i / 2] == dp[i] - 1) {
      i /= 2;
    }
    else {
      i /= 3;
    }
  }
  std::cout << "1\n";

  return 0;
}
