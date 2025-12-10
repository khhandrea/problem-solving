#include <iostream>

int A, C;

int power_mod(int power);

int main() {
  int B;
  std::cin >> A >> B >> C;

  A %= C;
  std::cout << power_mod(B) << '\n';

  return 0;
}

int power_mod(int power) {
  long long product;

  if (power == 1) {
    return A;
  }

  product = power_mod(power / 2);
  product = product * product % C;
  if (power % 2 == 1) {
    product = product * A % C;
  }

  return product;
}
