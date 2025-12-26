#include <iostream>

using namespace std;

int fruits[200000];
int count_fruit[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int left = 0;
    int max_num = 0;
    int kind = 0;
    for (int i = 0; i < N; i++) {
        int fruit;
        cin >> fruit;

        // Push
        fruits[i] = fruit;
        if (count_fruit[fruit] == 0) {
            kind += 1;
        }
        count_fruit[fruit] += 1;

        if (kind <= 2) {
            max_num += 1;
        }
        else {
            // Pop
            int front_fruit = fruits[left];
            count_fruit[front_fruit] -= 1;
            if (count_fruit[front_fruit] == 0) {
                kind -= 1;
            }
            left += 1;
        }
    }

    cout << max_num << '\n';

    return 0;
}