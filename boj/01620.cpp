#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M;
  std::string value;
  std::map<std::string, int> str_to_num;
  std::vector<std::string> num_to_str;

  std::cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    std::cin >> value;
    str_to_num.insert({value, i});
    num_to_str.push_back(value);
  }
  for (int i = 0; i < M; i++) {
    std::cin >> value;
    if (value[0] >= '1' && value[0] <= '9') {
      std::cout << num_to_str[std::stoi(value) - 1] << '\n';
    }
    else {
      std::cout << str_to_num[value] << '\n';
    }
  }

  return 0;
}

