#include <iostream>

int main() {
  short N;

  std::cin >> N;
  std::cout << (N % 2 == 0 ? "CY" : "SK") << '\n';

  return 0;
}
