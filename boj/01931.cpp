#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N, last = 0, count = 0;

  std::cin >> N;
  std::vector<std::pair<int, int> > times(N);
  for (int n = 0; n < N; n++) {
    std::cin >> times[n].second >> times[n].first;
  }

  std::sort(times.begin(), times.end());

  for (auto time: times) {
    if (last <= time.second) {
      last = time.first;
      count++;
    }
  }
  
  std::cout << count << '\n';

  return 0;
}
