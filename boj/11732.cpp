#include <iostream>
#include <set>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::set<short> s;
  std::set<short>::iterator iter;
  int M;
  std::string command;
  short value;

  std::cin >> M;
  for (int i = 0; i < M; i++) {
    std::cin >> command;
    
    if (command == "add") {
      std::cin >> value;
      s.insert(value);
    }
    else if (command == "remove") {
      std::cin >> value;
      iter = s.find(value);
      if (iter != s.end()) {
        s.erase(iter);
      }
    }
    else if (command == "check") {
      std::cin >> value;
      iter = s.find(value);
      std::cout << (iter == s.end() ? 0 : 1) << '\n';
    }
    else if (command == "toggle") {
      std::cin >> value;
      iter = s.find(value);
      if (iter != s.end()) {
        s.erase(iter);
      }
      else {
        s.insert(value);
      }
    }
    else if (command == "all") {
      for (short v = 1; v <= 20; v++) {
        s.insert(v);
      }
    }
    else if (command == "empty") {
      s.clear();
    }
  }

  return 0;
}
