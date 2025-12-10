#include <iostream>
#include <set>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N, M;
  long item;
  std::set<long> tree;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> item;
    tree.insert(item);
  }

  std::cin >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> item;
    std::cout << ((tree.find(item) == tree.end()) ? 0 : 1) << '\n';
  }

  return 0;
}
