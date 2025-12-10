#include <iostream>
#include <queue>
#include <functional>

int main() {
  int N, item, i;
  std::priority_queue<int, std::vector<int>, std::greater<int> > pqueue;

  std::cin >> N;

  for (i = 0 ; i < N; i++) {
    std::cin >> item;
    pqueue.push(item);
  }

  for (i = 0; i < N; i++) {
    item = pqueue.top();
    std::cout << item << '\n';
    pqueue.pop();
  }

  return 0;
}
