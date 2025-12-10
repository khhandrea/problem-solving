#include <cstring>
#include <iostream>

char** map;

void print_star(short row, short col, short size) {
  if (size == 3) {
    map[row][col] = '*';
    map[row + 1][col - 1] = '*';
    map[row + 1][col + 1] = '*';
    for (short i = 0; i < 5; i++) {
      map[row + 2][col - 2 + i] = '*';
    }
    return;
  }

  size /= 2;
  print_star(row, col, size);
  print_star(row + size, col - size, size);
  print_star(row + size, col + size, size);
}

int main() {
  short N;
  std::cin >> N;

  // Initialize
  map = new char*[N];
  for (short i = 0; i < N; i++) {
    map[i] = new char[2 * N - 1];
    std::memset(map[i], ' ', (2 * N - 1) * sizeof(char));
  }

  print_star(0, N - 1, N);

  for (short i = 0; i < N; i++) {
    std::cout << map[i] << '\n';;
  }

  return 0;
}
