#include <iostream>

int main() {
  short N, M, next_vip = 0;
  short *vips;
  int dp[3] = {1, 1, 1};

  std::cin >> N >> M;
  vips = new short[M];

  for (short m = 0; m < M; m++) {
    std::cin >> vips[m];
  }

  for (short n = 1; n <= N; n++) {
    dp[0] = dp[1];
    dp[1] = dp[2];

    if (vips[next_vip] != n && vips[next_vip - 1] != n - 1) {
      dp[2] += dp[0];
    }

    if (vips[next_vip] == n) {
      vips++;
    }
  }

  std::cout << dp[2] << '\n';

  return 0;
}
