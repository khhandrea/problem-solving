#include <iostream>
#include <map>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int result;
  short T, N;
  std::string name, type;
  std::map<std::string, int> nums;

  std::cin >> T;
  for (short t = 0; t < T; t++) {
    std::cin >> N;
    // Input
    for (short n = 0; n < N; n++) {
      std::cin >> name >> type;
      if (nums.find(type) != nums.end()) {
        nums[type] += 1;
      }
      else {
        nums.insert({type, 2});
      }
    }

    // Calculate
    result = 1;
    for (auto iter = nums.begin(); iter != nums.end(); iter++) {
      result *= iter->second;
    }
    std::cout << result - 1 << '\n';
    nums.clear();
  }

  return 0;
}
