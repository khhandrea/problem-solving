#include <iostream>

int main() {
  short N;
  long long temp, case_nums[2];

  std::cin >> N;
  case_nums[0] = 1;
  case_nums[1] = 1;

  for (short n = 2; n < N; n++) {
    temp = case_nums[1];
    case_nums[1] = case_nums[0] + case_nums[1];
    case_nums[0] = temp;
  }

  std::cout << case_nums[1] << '\n';

  return 0;
}
