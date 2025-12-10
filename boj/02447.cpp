#include <cmath>
#include <iostream>

char **map;

void print_star(short row, short col, short size, bool fill) {
  bool fill_sub;

  if (size == 1) {
    map[row][col] = (fill ? '*' : ' ');
    return;
  }

  size /= 3;
  for (short i = 0; i < 3; i++) {
    for (short j = 0; j < 3; j++) {
      fill_sub = fill && (i != 1 || j != 1);
      print_star(row + i * size, col + j * size, size, fill_sub);
    }
  }
}

int main() {
  short N;

  std::cin >> N;
  map = new char*[N];
  for (short i = 0; i < N; i++) {
    map[i] = new char[N];
  }

  print_star(0, 0, N, true);

  for (short i = 0; i < N; i++) {
    std::cout << map[i] << '\n';
  }
}
