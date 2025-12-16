#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    int result = 0;
    string num_buffer = "";
    bool is_minus = false;

    for (int i = 0; i <= input.size(); i++) {
        if (i == input.size() || input[i] == '-' || input[i] == '+') {
            int current_num = stoi(num_buffer);

            if (is_minus) {
                result -= current_num;
            }
            else {
                result += current_num;
            }

            if (input[i] == '-') {
                is_minus = true;
            }

            num_buffer = "";
        }
        else {
            num_buffer += input[i];
        }
    }

    cout << result << '\n';

    return 0;
}