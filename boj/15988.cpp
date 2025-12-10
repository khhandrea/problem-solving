#include <iostream>
#include <vector>
#define MOD 1000000009

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, T, size = 3;
  std::vector<unsigned int> dp = {1, 2, 4};
  
  std::cin >> T;
  for (int t = 0; t < T; t++) {
    std::cin >> n;
    
    while(size < n) {
      dp.push_back((dp[size - 1] + dp[size - 2] + dp[size - 3]) % MOD);
      size++;
    }
    std::cout << dp[n - 1] << '\n';
  }

  return 0;
}
