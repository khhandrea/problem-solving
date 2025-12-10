#include <iostream>
#include <queue>
#include <string>

struct Profile {
  std::pair<short, int> age_order;
  std::string name;

  bool operator<(const Profile &r) const {
    return (age_order > r.age_order);
  }
};

std::ostream& operator<<(std::ostream& os, const Profile &profile) {
  return os << profile.age_order.first << ' ' << profile.name;
}

int main() {
  int N;
  Profile profile;
  std::priority_queue<Profile> pq;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> profile.age_order.first >> profile.name;
    profile.age_order.second = i;
    pq.push(profile);
  }

  for (int i = 0; i < N; i++) {
    profile = pq.top();
    std::cout << pq.top() << '\n';
    pq.pop();
  }

  return 0;
}
