#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Profile {
  short age;
  std::string name; 

  bool operator<(const Profile &r) const {
    return age < r.age;
  }
};

std::ostream &operator<<(std::ostream& os, const Profile &profile) {
  return os << profile.age << ' ' << profile.name;
}

int main() {
  int N, age;
  Profile profile;
  std::vector<Profile> v;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> profile.age >> profile.name;
    v.push_back(profile);
  }

  std::stable_sort(v.begin(), v.end());

  for (auto item: v) {
    std::cout << item << '\n';
  }
  return 0;
}
