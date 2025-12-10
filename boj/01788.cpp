#include <iostream>
#define MOD 1000000000

int main() {
  short sign;
  int n, temp, abs;
  int dp[2] = {0, 1};

  std::cin >> n;

  if (n < 0) {
    for (int i = -1; i >= n; i--) {
      temp = (dp[1] - dp[0]) % MOD;
      dp[1] = dp[0] % MOD;
      dp[0] = temp % MOD;
    }
  }
  else if (n <= 1){
    temp = dp[n];
  }
  else {
    for (int i = 2; i <= n; i++) {
      temp = (dp[0] + dp[1]) % MOD;
      dp[0] = dp[1] % MOD;
      dp[1] = temp % MOD;
    }
  }

  abs = temp;
  if (temp < 0) {
    sign = -1;
    abs *= -1;
  }
  else if (temp > 0) {
    sign = 1;
  }
  else {
    sign = 0;
  }

  std::cout << sign << '\n';
  std::cout << abs << '\n';

  return 0;
}
