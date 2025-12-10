#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short N;
  short *A;
  int max_inc_sum;
  int *max_inc_sums;

  std::cin >> N;
  A = new short[N];
  max_inc_sums = new int[N];
  for (short n = 0; n < N; n++) {
    std::cin >> A[n];
  }

  max_inc_sums[0] = max_inc_sum = A[0];
  for (short n = 0; n < N; n++) {
    max_inc_sums[n] = A[n];
    for (short i = 0; i < n; i++) {
      if (A[i] < A[n] && max_inc_sums[i] + A[n] > max_inc_sums[n]) {
        max_inc_sums[n] = max_inc_sums[i] + A[n];
      }
    }
    if (max_inc_sums[n] > max_inc_sum) {
      max_inc_sum = max_inc_sums[n];
    }
  }

  std::cout << max_inc_sum << '\n';

  return 0;
}
