#include <iostream>

int max(int a, int b, int c, int d) {
  int result = a;
  result = (b > result ? b : result);
  result = (c > result ? c : result);
  result = (d > result ? d : result);
  return result;
}

void shift(int* arr) {
  arr[0] = arr[1];
  arr[1] = arr[2];
  arr[2] = arr[3];
}

int main() {
  short n, volume;
  int dp1[4] = {0, 0, 0, 0}, dp2[4] = {0, 0, 0, 0};
  int max_volume = 0;

  std::cin >> n;

  for (short i = 0; i < n; i++) {
    std::cin >> volume;

    shift(dp1);
    shift(dp2);
    dp1[3] = max(dp1[0], dp1[1], dp2[0], dp2[1]) + volume;
    dp2[3] = dp1[2] + volume;

    max_volume = max(dp1[3], dp2[3], max_volume, -1);
  }

  std::cout << max_volume << '\n';

  return 0;
}
