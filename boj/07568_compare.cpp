#include <iostream>
#include <string>
#include <vector>

struct ProfileInput {
  short weight;
  short height;
};

struct ProfileBF {
  short height;
  short weight;
  short rank;

  bool operator>(const ProfileBF &r) const {
    return ((height > r.height) && (weight > r.weight));
  }
};

std::string brute_force(std::vector<ProfileInput> &input) {
  std::string result = " ";
  return result;
}

std::string heap(std::vector<ProfileInput> input) {
  std::string result = " ";
  return result;
}

int main() {
  short N;
  ProfileInput profile;
  std::vector<ProfileInput> v_input;

  while (true) {
    std::cin >> N;
    v_input.clear();
    for (short i = 0; i < N; i++) {
      std::cin >> profile.weight >> profile.height;
      v_input.push_back(profile);
    }

    if (brute_force(v_input).compare(heap(v_input)) != 0) {
      std::cout << "Different!\n";
      std::cout << "Brute force: " << brute_force(v_input) << '\n';
      std::cout << "Heap: " << heap(v_input) << '\n';
    }
    else {
      std::cout << "Pass\n";
    }
  }

  return 0;
}

