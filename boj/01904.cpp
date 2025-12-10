#include <iostream>

int main() {
  int N;
  short dp[3] = {1, 2, 3};
  std::cin >> N;
  
  if (N <= 2) {
    dp[2] = N;
  }
  else {
    for (int n = 2; n < N; n++) {
      dp[0] = dp[1] % 15746;
      dp[1] = dp[2] % 15746;
      dp[2] = (dp[0] + dp[1]) % 15746;
    }
  }

  std::cout << dp[2] << '\n';
}
