#include <algorithm>
#include <iostream>

int main() {
  int N, cur_weight, max_total = 0;
  short *weights;

  std::cin >> N;
  weights = new short[N];
  for (int i = 0; i < N; i++) {
    std::cin >> weights[i];
  }

  std::sort(weights, weights + N);

  for (int i = N - 1; i >= 0; i--) {
    cur_weight = weights[i] * (N - i);
    if (cur_weight > max_total) {
      max_total = cur_weight;
    }
  }

  std::cout << max_total << '\n';

  return 0;
}
