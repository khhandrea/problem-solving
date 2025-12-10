#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short N, x1, y1, x2, y2;
  int M;
  unsigned int **mat;
  unsigned int partial_sum;

  std::cin >> N >> M;

  // Input and make sum matrix
  mat = new unsigned int*[N + 1];
  for (short row = 0; row <= N; row++) {
    mat[row] = new unsigned int[N + 1];
    for (short col = 0; col <= N; col++) {
      if (row == 0 || col == 0) {
        mat[row][col] = 0;
        continue;
      }

      std::cin >> mat[row][col];
      mat[row][col] += mat[row - 1][col] + mat[row][col - 1] - mat[row - 1][col - 1];
    }
  }
 
  // Input and print parital sum
  for (int m = 0; m < M; m++) {
    std::cin >> x1 >> y1 >> x2 >> y2;
    partial_sum = mat[x2][y2] - mat[x1 - 1][y2] - mat[x2][y1 - 1] + mat[x1 - 1][y1 - 1];
    std::cout << partial_sum << '\n';
  }

  return 0;
}
