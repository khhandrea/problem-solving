#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Profile {
  short index;
  short weight;
  short height;

  bool operator<(const Profile &r) const {
    return weight < r.weight;
  }
};

int main() {
  short N, prev_weight = 0;
  short *ranks;
  Profile profile;
  std::vector<Profile> v;
  std::vector<short> height_buffer;
  std::multiset<short> great_heights;

  std::cin >> N;
  ranks = new short[N];
  for (short i = 0; i < N; i++) {
    profile.index = i;
    std::cin >> profile.weight >> profile.height;
    v.push_back(profile);
  }

  // Sort profiles by weight
  std::sort(v.begin(), v.end());

  // Scan data in order of great weight
  for (short i = N - 1; i >= 0; i--) {
    // Add height in great_heights if weight is different
    if ((v[i].weight != prev_weight)) {
      for (auto item: height_buffer) {
        great_heights.insert(item);
      }
      height_buffer.clear();
    }

    ranks[v[i].index] = std::distance(great_heights.upper_bound(v[i].height), great_heights.end()) + 1;
    height_buffer.push_back(v[i].height);
    prev_weight = v[i].weight;
  }

  for (short i = 0; i < N; i++) {
    std::cout << ranks[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}
