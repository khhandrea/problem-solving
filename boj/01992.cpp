#include <iostream>
#include <string>

std::string *image;
std::string result = "";

void make_quad_tree(short row, short col, short size);

int main() {
  short N;

  std::cin >> N;
  image = new std::string[N];
  for (short i = 0; i < N; i++) {
    std::cin >> image[i];
  }

  make_quad_tree(0, 0, N);

  std::cout << result << '\n';

  return 0;
}

void make_quad_tree(short row, short col, short size) {
  bool same = true;
  char first = image[row][col];

  for (short i = 0; i < size && same; i++) {
    for (short j = 0; j < size && same; j++) {
      if (image[row + i][col + j] != first) {
        same = false;
      }
    }
  }


  if (same) {
    result += first;
  }
  else {
    result += '(';
    size /= 2;
    make_quad_tree(row, col, size);
    make_quad_tree(row, col + size, size);
    make_quad_tree(row + size, col, size);
    make_quad_tree(row + size, col + size, size);
    result += ')';
  }
}
