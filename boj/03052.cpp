#include <iostream>
#include <set>

using std::cin, std::cout;
using std::set;

int main() {
    int number;
    set<int> modulos;

    for (int i=0; i<10; i++) {
        cin >> number;
        modulos.insert(number % 42);
    }

    cout << modulos.size() << '\n';

    return 0;
}