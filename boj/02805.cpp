#include <algorithm>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  unsigned int sum;
  int N, M, mid, low, high, max = 0;
  int *heights;

  std::cin >> N >> M;
  heights = new int[N];
  for (int n = 0; n < N; n++) {
    std::cin >> heights[n];
  }

  std::sort(heights, heights + N);
  low = 0;
  high = heights[N - 1];

  // Maximum parametric search
  while (high >= low){
    mid = (static_cast<unsigned int>(high) + low) / 2;
    sum = 0;
    for (int i = N - 1; heights[i] > mid && sum < M; i--) {
      sum += heights[i] - mid;
    }

    if (sum < M) {
      high = mid - 1;
    }
    else {
      max = mid;
      low = mid + 1;
    }
  }

  std::cout << max << '\n';

  return 0;
}
