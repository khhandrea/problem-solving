#include <iostream>

short paper[128][128];
short blue = 0;
short white = 0;

void count(short row, short col, short size);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short N;

  std::cin >> N;
  for (short i = 0; i < N; i++) {
    for (short j = 0; j < N; j++) {
      std::cin >> paper[i][j];
    }
  }

  count(0, 0, N);

  std::cout << white << '\n';
  std::cout << blue << '\n';
}

void count(short row, short col, short size) {
  bool same = true;
  short lefttop = paper[row][col];
  
  // Count
  for (short i = 0; i < size && same; i++) {
    for (short j = 0; j < size && same; j++) {
      if (paper[row + i][col + j] != lefttop) {
        same = false;
      }
    }
  }
  
  // Output
  if (same) {
    if (lefttop == 1) {
      blue++;
    }
    else {
      white++;
    }
    return;
  }

  size /= 2;
  count(row, col, size);
  count(row + size, col, size);
  count(row, col + size, size);
  count(row + size, col + size, size);
}
