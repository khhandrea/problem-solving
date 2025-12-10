#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short T, N;
  std::vector<int> result_table = {1, 0, 1};

  std::cin >> T;
  for (short i = 0; i < T; i++) {
    std::cin >> N;

    for (int i = result_table.size(); i <= N + 2; i++) {
      result_table.push_back(result_table[i - 1] + result_table[i - 2]);
    }

    std::cout << result_table[N] << ' ' << result_table[N + 1] << '\n';
  }

  return 0;
}
