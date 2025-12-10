#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, std::string> table;
    std::string address, password;
    int N, M;

    std::cin >> N >> M;

    // Insert address and password
    for (int n = 0; n < N; n++) {
        std::cin >> address >> password;
        table.insert({address, password});
    }

    // Print password
    for (int m = 0; m < M; m++) {
        std::cin >> address;
        std::cout << table[address] << '\n';
    }

    return 0;
}
