#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  if (n == 0) {
    std::cout << "0\n";
    return 0;
  }

  short arr[n];
  short item;
  int total = 0, truncated = std::round(n * 0.15);
  
  for (int i = 0; i < n; i++) {
    std::cin >> item;
    arr[i] = item;
  }

  std::sort(arr, arr + n);

  for (int i = truncated; i < n - truncated; i++) {
    total += arr[i];
  }

  total = std::round((double)total / (n - 2 * truncated));
  std::cout << total << '\n';

  return 0;
}
