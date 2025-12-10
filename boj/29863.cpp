#include <iostream>

using std::cin, std::cout;

int main() {
    unsigned int A, B, total = 0;

    cin >> A >> B;

    total = B - A;
    if (A >= 20) {
        total += 24;
    }

    cout << total << '\n';

    return 0;
}