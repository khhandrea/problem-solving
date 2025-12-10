#include <iostream>
#include <map>
#include <set>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, value, idx;
  int *Xs;
  std::set<int> coord_set;
  std::map<int, int> ranks;

  std::cin >> N;
  Xs = new int[N];
  for (int n = 0; n < N; n++) {
    std::cin >> value;
    Xs[n] = value;
    coord_set.insert(value);
  }

  idx = coord_set.size() - 1;
  for (auto iter = coord_set.rbegin(); iter != coord_set.rend(); iter++) {
    ranks.insert({*iter, idx--});
  }

  for (int n = 0; n < N; n++) {
    std::cout << ranks[Xs[n]] << ' ';
  }
  std::cout << '\n';

  return 0;
}
