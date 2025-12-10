#include <iostream>

using std::cout, std::cin;

int main() {
  unsigned long N;
  int step, result = 1;
  
  cin >> N;

  for (step=0; N>result; step++) {
    result += (step + 1) * 6;
  }

  cout << step + 1 << '\n';

  return 0;
}
