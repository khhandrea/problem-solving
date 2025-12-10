#include <cmath>
#include <iostream>

void print_move(short layer, short from, short mid, short to);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short N;

  std::cin >> N;

  std::cout << (int)std::pow(2, N) - 1 << '\n';
  print_move(N, 1, 2, 3);

  return 0;
}

void print_move(short layer, short from, short mid, short to) {
  if (layer == 1) {
    std::cout << from << ' ' << to << '\n';
    return;
  }
  
  print_move(layer - 1, from, to, mid);
  print_move(1, from, 0, to);
  print_move(layer - 1, mid, from, to);
}
