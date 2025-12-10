#include <iostream>
#include <string>

int main() {
  short i;
  std::string input;
  bool fb = false;

  for (i = 0; i < 3; i++) {
    std::cin >> input;
    if ((input.find("Fizz") == std::string::npos) 
        && (input.find("Buzz") == std::string::npos)) {
      if ((std::stoi(input) + (3 - i)) % 3 == 0) {
        std::cout << "Fizz";
        fb = true;
      }
      if ((std::stoi(input) + (3 - i)) % 5 == 0) {
        std::cout << "Buzz";
        fb = true;
      }
      if (!fb) {
        std::cout << std::stoi(input) + (3 - i);
      }
      std::cout << '\n';
      break;
    }
  }

  return 0;
}
