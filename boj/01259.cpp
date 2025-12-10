#include <iostream>
#include <string>

int main() {
  std::string N;
  int i;
  bool result;

  while (true) {
    std::cin >> N;

    if (N.compare("0") == 0) {
      break;
    }

    result = true;
    for (i = 0; i <= N.length() / 2; i++) {
      if (N[i] != N[N.length() - i - 1]) {
        result = false;
        break;
      }
    }

    std::cout << (result ? "yes" : "no") << '\n';
  }

  return 0;
}

