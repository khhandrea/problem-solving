#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  short K;
  int N, len, n_mid, ans;
  int mid, r = 0, l = 1;
  int *lens;

  // Input
  std::cin >> K >> N;
  lens = new int[K];
  for (short i = 0; i < K; i++) {
    std::cin >> lens[i];
    r = ((lens[i] > r) ? lens[i] : r);
  }

  // Parametric search
  while ((r >= l) && (l > 0)) {
    mid = 0.5 * l + 0.5 * r;
    n_mid = 0;
    for (short i = 0; i < K; i++) {
      n_mid += lens[i] / mid;
    }

    if (n_mid >= N) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  std::cout << ans << '\n';

  return 0;
}
