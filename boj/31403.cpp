#include <iostream>
#include <string>

int main() {
    using namespace std;

    string A, B;
    int C, int_result, str_result;

    std::cin >> A >> B >> C;
    int_result = stoi(A) + stoi(B) - C;
    str_result = stoi(A + B) - C;

    std::cout << int_result << '\n';
    std::cout << str_result << '\n';
    return 0;
}