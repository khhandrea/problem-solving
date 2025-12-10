#include <iostream>

int main() {
  long long temp, fib_temp[2] = {0, 1};
  short N;

  std::cin >> N;
  for (short n = 1; n < N; n++) {
    temp = fib_temp[1];
    fib_temp[1] += fib_temp[0];
    fib_temp[0] = temp;
  }

  std::cout << fib_temp[1] << '\n';

  return 0;
}
