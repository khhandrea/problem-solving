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

    int star_weight_inverse = (star_weight == 3 ? 7 : 1);
    int star = (((star_weight_inverse * -weighted_sum) % 10) + 10) % 10;
    
    cout << star << '\n';

    return 0;
}