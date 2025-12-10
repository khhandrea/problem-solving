#include <iostream>

int main() {
  short N;
  std::cin >> N;

  std::cout << ((N - 2) % 7 == 0 || N % 7 == 0 ? "CY" : "SK") << '\n';
  return 0;
}
