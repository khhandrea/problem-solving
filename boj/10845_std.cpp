#include <iostream>
#include <queue>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  short N;
  int value;
  std::string command;
  std::queue<int> q;

  std::cin >> N;
  for (short i = 0; i < N; i++) {
    std::cin >> command;
    if (command == "push") {
      std::cin >> value;
      q.push(value);
    }
    else if (command == "pop") {
      if (q.empty()) {
        value = -1;
      }
      else {
        value = q.front();
        q.pop();
      }
      std::cout << value << '\n';
    }
    else if (command == "size") {
      std::cout << q.size() << '\n';
    }
    else if (command == "empty") {
      std::cout << q.empty() << '\n';
    }
    else if (command == "front") {
      if (q.empty()) {
        value = -1;
      }
      else {
        value = q.front();
      }
      std::cout << value << '\n';
    }
    else if (command == "back") {
      if (q.empty()) {
        value = -1;
      }
      else {
        value = q.back();
      }
      std::cout << value << '\n';
    }
  }

  return 0;
}
