#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  std::cin.tie(NULL);

  bool able = true;
  int n, value, pos = 0, next = 1;
  int iter;
  std::stack<int> stack;
  std::vector<char> result;

  std::cin >> n;
  for (int step = 0; step < n; step++) {
    std::cin >> value;

    if (able) {
      if (value >= next) {
        iter = value - next + 1; 
        for (int i = 0; i < iter; i++) {
          stack.push(next++);
          result.push_back('+');
        }
      }
      if (value < next) {
        if (stack.top() == value) {
          result.push_back('-');
          stack.pop();
        }
        else {
          able = false;
        }
      }
    }
  }

  if (able) {
    for (auto op: result) {
      std::cout << op << '\n';
    }
  }
  else {
    std::cout << "NO\n";
  }

  return 0;
}
