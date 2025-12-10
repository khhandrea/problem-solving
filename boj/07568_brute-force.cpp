#include <iostream>
#include <vector>

struct Profile {
  short height;
  short weight;
  short rank;

  bool operator>(const Profile &r) const {
    return ((height > r.height) && (weight > r.weight));
  }
};

int main() {
  short N;
  Profile profile;
  std::vector<Profile> v;

  std::cin >> N;
  for (short i = 0; i < N; i++) {
    std::cin >> profile.weight >> profile.height;
    v.push_back(profile);
  }

  for (short i = 0; i < N; i++) {
    v[i].rank = 1;
    for (short j = 0; j < N; j++) {
      v[i].rank += (v[j] > v[i]);
    }
  }

  for (auto item: v) {
    std::cout << item.rank << ' ';
  }
  std::cout << '\n';

  return 0;
}
