#include <algorithm>
#include <iostream>

struct Coord {
  int x;
  int y;

  bool operator<(const Coord &r) const {
    if (y != r.y) {
      return (y < r.y);
    }
    else {
      return (x < r.x);
    }
  }
};

std::ostream &operator<<(std::ostream &os, Coord r) {
  return (os << r.x << ' ' << r.y);
}

int main() {
  int N;
  Coord coords[100000];

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> coords[i].x >> coords[i].y;
  }

  std::sort(coords, coords + N);

  for (int i = 0; i < N; i++) {
    std::cout << coords[i] << '\n';
  }
  return 0;
}
