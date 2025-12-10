#include <iostream>
#include <algorithm>

int main() {
  int N, M, card, sum, result = 0;
  short i, j, k;
  int cards[100];

  std::cin >> N >> M;
  for (i = 0; i < N; i++) {
    std::cin >> card;
    cards[i] = card;
  }
  std::sort(cards, cards + N);

  for (i = 0; i < N - 2; i++) {
    for (j = i + 1; j < N - 1; j++) {
      sum = cards[i] + cards[j];
      if (sum > M) {
        break;
      }
      for (k = j + 1; k < N; k++) {
        sum = cards[i] + cards[j] + cards[k];
        if (sum > M) {
          break;
        }
        result = (sum > result) ? sum : result;
      }
    }
  }
  std::cout << result << '\n';

  return 0;
}
