#include <iostream>

int main() {
  int num;
  short N = 0, target_N;

  std::cin >> target_N;

  for (num = 666; N < target_N; num++) {
    if (std::to_string(num).find("666") != std::string::npos) {
      N += 1;
    }
  }

  std::cout << num - 1 << '\n';

  return 0;
}
