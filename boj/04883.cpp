#include <iostream>

int min(int a, int b) {
  return (a > b ? b : a);
}

int min(int a, int b, int c) {
  return (a > b ? min(b, c) : min(a, c));
}

int min(int a, int b, int c, int d) {
  return min(min(a, b), min(c, d));
}

void copy(int *from, int *to) {
  for (short i = 0; i < 3; i++) {
    to[i] = from[i];
  }
}

void init(int *w) {
  w[0] = w[1] = w[2] = 1001;
}

int main() {
  int N, t = 1;
  int w[3], last_w[3];

  while (true) {
    std::cin >> N;

    if (N == 0) {
      break;
    }

    init(last_w);
    for (int n = 0; n < N; n++) {
      std::cin >> w[0] >> w[1] >> w[2];

      w[0] += min(last_w[0], last_w[1]);
      // Check first row for the start node
      if (n > 0) {
        w[1] += min(w[0], last_w[0], last_w[1], last_w[2]);
      }
      w[2] += min(w[1], last_w[1], last_w[2]);

      copy(w, last_w);
    }
    std::cout << t++ << ". " << w[1] << '\n';
  }

  return 0;
}
