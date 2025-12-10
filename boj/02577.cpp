#include <iostream>
#include <string>
#include <map>

int main() {
    int A, B, C;
    unsigned int result;
    std::map<char, int> counter;
    for (char digit='0'; digit<='9'; digit++) {
        counter[digit] = 0;
    }

    std::cin >> A >> B >> C;
    result = A * B * C;
    for (char digit: std::to_string(result)) {
        counter[digit] += 1;
    }
    for (auto iter: counter) {
        std::cout << iter.second << '\n';
    }
    return 0;
}