#include <iostream>
#include <string>

class Queue {
private:
  int *queue;
  short front = 0, back = 0;

public:
  Queue(short max_size) {
    queue = new int[max_size];
  }

  short get_size() {
    return back - front;
  }

  bool is_empty() {
    return (get_size() == 0);
  }

  void push(int x) {
    queue[back] = x;
    back++;
  }

  int pop() {
    int result;
    if (is_empty()) {
      return -1;
    }
    return queue[front++];
  }

  int get_front() {
    if (is_empty()) {
      return -1;
    }
    return queue[front];
  }

  int get_back() {
    if (is_empty()) {
      return -1;
    }
    return queue[back - 1];
  }
};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  short N;
  int value;
  std::string command;

  std::cin >> N;
  Queue q(N);

  for (short i = 0; i < N; i++) {
    std::cin >> command;
    if (command == "push") {
      std::cin >> value;
      q.push(value);
    }
    else if (command == "pop") {
      std::cout << q.pop() << '\n';
    }
    else if (command == "size") {
      std::cout << q.get_size() << '\n';
    }
    else if (command == "empty") {
      std::cout << q.is_empty() << '\n';
    }
    else if (command == "front") {
      std::cout << q.get_front() << '\n';
    }
    else if (command == "back") {
      std::cout << q.get_back() << '\n';
    }
  }

  return 0;
}
