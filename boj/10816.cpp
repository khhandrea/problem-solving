#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N, M, item;
  std::vector<int> v;
  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> range;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> item;
    v.push_back(item);
  }

  std::sort(v.begin(), v.end());

  std::cin >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> item;
    range = std::equal_range(v.begin(), v.end(), item);
    std::cout << std::distance(range.first, range.second) << ' ';
  }
  std::cout << '\n';

  return 0;
}
