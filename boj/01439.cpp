#include <iostream>

int main() {
  int count = 0;
  char c, last = 0;

  while ((c = std::cin.get()) != '\n') {
    count += (last && c != last);
    last = c;
  }

  std::cout << (count + 1) / 2 << '\n';

  return 0;
}
