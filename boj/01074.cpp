#include <cmath>
#include <iostream>

short N;
int r, c, count = 0;
bool found = false;

void traverse(int row, int col, int size) {
  if (found) {
    return;
  }

  if (r >= (unsigned int)row + size || c >= (unsigned int)col + size) {
    count += size * size;
    return;
  }

  if (row == r && col == c) {
    std::cout << count << '\n';
    found = true;
    return;
  }

  size /= 2;
  for (short i = 0; i < 2 && !found; i++) {
    for (short j = 0; j < 2 && !found; j++) {
      traverse(row + i * size, col + j * size, size);
    }
  }
}

int main() {
  std::cin >> N >> r >> c;
  traverse(0, 0, (int)std::pow(2, N));
  return 0;
}

