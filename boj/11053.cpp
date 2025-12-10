#include <iostream>

int main() {
  short N, max_inc, max_max = 1;
  short *array, *max_incs;

  std::cin >> N;
  array = new short[N];
  for (short n = 0; n < N; n++) {
    std::cin >> array[n];
  }

  max_incs = new short[N];
  for (short n = 0; n < N; n++) {
    max_inc = 0;
    for (short i = 0; i < n; i++) {
      if (array[i] < array[n] && max_incs[i] > max_inc) {
        max_inc = max_incs[i];
      }
    }

    max_incs[n] = max_inc + 1;

    if (max_incs[n] > max_max) {
      max_max = max_incs[n];
    }
  }

  std::cout << max_max << '\n';

  return 0;
}
