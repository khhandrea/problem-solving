#include <iostream>

int main() {
  short target_N, N = 0, prev_digit = -1, post_digit;
  std::cin >> target_N;

  do {
    N++;
    prev_digit++;
    post_digit = 666;

    if (prev_digit % 1000 == 666) {
      for (post_digit = 0;
           (post_digit < 999) && (N < target_N);
           post_digit++, N++);
    }
    else if (prev_digit % 100 == 66) {
      for (post_digit = 600;
           (post_digit < 699) && (N < target_N);
           post_digit++, N++);
    }
    else if (prev_digit % 10 == 6) {
      post_digit = 660;
      for (post_digit = 660;
           (post_digit < 669) && (N < target_N);
           post_digit++, N++);
    }
  } while (N < target_N);

  if (prev_digit) {
    std::cout << prev_digit;
  }
  std::printf("%03hd\n", post_digit);

  return 0;
}
