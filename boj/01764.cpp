#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M;
  std::string value;
  std::set<std::string> no_heard;
  std::vector<std::string> no_seen_heard;

  std::cin >> N >> M;
  for (int i = 0; i < N; i++) {
    std::cin >> value;
    no_heard.insert(value);
  }
  
  for (int i = 0; i < M; i++) {
    std::cin >> value;
    if (no_heard.find(value) != no_heard.end()) {
      no_seen_heard.push_back(value);
    }
  }

  std::sort(no_seen_heard.begin(), no_seen_heard.end());

  // Output
  std::cout << no_seen_heard.size() << '\n';
  for (std::string item: no_seen_heard) {
    std::cout << item << '\n';
  }

  return 0;
}
