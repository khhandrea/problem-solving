#include <iostream>
#include <string>
#include <set>


struct Compare {
  // Operator overloading
  bool operator() (const std::string& left, const std::string& right) const {
    if (left.length() != right.length()) {
      return left.length() < right.length();
    }
    else {
      return left < right;
    }
  }
};


int main() {
  short N, i;
  std::string word;

  std::cin >> N;
  std::set<std::string, Compare> dic;

  for (i = 0; i < N; i++) {
    std::cin >> word;
    dic.insert(word);
  }

  for (std::string item: dic) {
    std::cout << item << '\n';
  }

  return 0;
}
