#include <iostream>

struct Triple {
  int plus;
  int zero;
  int minus;
};

Triple count(short **paper, short row, short col, short size) {
  bool same = true;
  Triple result = {0, 0, 0}, small;

  // Base case
  if (size == 1) {
    if (paper[row][col] == -1) {
      result.minus = 1;
    }
    else if (paper[row][col] == 0) {
      result.zero = 1;
    }
    else if (paper[row][col] == 1) {
      result.plus = 1;
    }
    return result;
  }

  // Count
  for (short i = 0; i < size; i++) {
    for (short j = 0; j < size; j++) {
      if (paper[row + i][col + j] != paper[row][col]) {
        same = false;
        break;
      }
    }
    if (!same) {
      break;
    }
  }

  // Return
  if (same) {
    if (paper[row][col] == -1) {
      result.minus = 1;
    }
    else if (paper[row][col] == 0) {
      result.zero = 1;
    }
    else if (paper[row][col] == 1) {
      result.plus = 1;
    }
  }
  else {
    for (short i = 0; i < 3; i++) {
      for (short j = 0; j < 3; j++) {
        small = count(paper, row + (size / 3) * i, col + (size / 3) * j, size / 3);
        result.plus += small.plus;
        result.zero += small.zero;
        result.minus += small.minus;
      }
    }
  }
  return result;
};

int main() {
  short N;
  short **paper;
  Triple result;

  std::cin >> N;
  paper = new short*[N];
  for (short i = 0; i < N; i++) {
    paper[i] = new short[N];
    for (short j = 0; j < N; j++) {
      std::cin >> paper[i][j];
    }
  }

  result = count(paper, 0, 0, N);
  std::cout << result.minus << '\n';
  std::cout << result.zero << '\n';
  std::cout << result.plus << '\n';

  return 0;
}
