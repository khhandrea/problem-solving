#include <iostream>

int main() {
  int N, max_subsum;
  int *nums, *max_subsums;

  std::cin >> N;
  nums = new int[N];
  max_subsums = new int[N];
  for (int n = 0; n < N; n++) {
    std::cin >> nums[n];
  }

  max_subsum = max_subsums[0] = nums[0];
  for (int n = 1; n < N; n++) {
    max_subsums[n] = nums[n];
    if (max_subsums[n - 1] > 0) {
      max_subsums[n] += max_subsums[n - 1];
    }

    if (max_subsums[n] > max_subsum) {
      max_subsum = max_subsums[n];
    }
  }

  std::cout << max_subsum << '\n';

  return 0;
}
