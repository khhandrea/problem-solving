#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::vector<int>::iterator unique_end, unique_find;

  // Input
  std::cin >> N;
  std::vector<int> Xs(N);
  for (int n = 0; n < N; n++) {
    std::cin >> Xs[n];
  }

  // Make unique vector
  std::vector<int> Xs_unique(Xs);
  std::sort(Xs_unique.begin(), Xs_unique.end());
  unique_end = std::unique(Xs_unique.begin(), Xs_unique.end());

  // Print index of unique vector
  for (int n = 0; n < N; n++) {
    unique_find = std::lower_bound(Xs_unique.begin(), unique_end, Xs[n]);
    std::cout << unique_find - Xs_unique.begin() << ' ';
  }
  std::cout << '\n';
}
