#include <iostream>

int main() {
  short N;
  short *dp;

  std::cin >> N;
  dp = new short[N];
  dp[0] = 1;
  dp[1] = 3;
  
  for (short n = 2; n < N; n++) {
    dp[n] = (dp[n - 1] + dp[n - 2] * 2) % 10007;
  }

  std::cout << dp[N - 1] << '\n';

  return 0;
}
