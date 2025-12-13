#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string isbn;
    cin >> isbn;

    int weighted_sum = 0;
    int star_weight;

    for (int i = 0; i < 13; i++) {
        int weight = (i % 2 == 0 ? 1 : 3);

        if (isbn[i] == '*') {
            star_weight = weight;
        }
        else {
            weighted_sum += weight * (isbn[i] - '0');
        }
    }

    for (int star = 0; star < 10; star++) {
        int total = weighted_sum + star_weight * star;
        if (total % 10 == 0) {
            cout << star << '\n';
            return 0;
        }
    }

    return 0;
}