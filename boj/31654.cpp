#include <iostream>

using std::cin, std::cout;

int main() {
    long A, B, C;

    cin >> A >> B >> C;

    cout << ((A + B == C) ? "correct!" : "wrong!") << '\n';

    return 0;
}