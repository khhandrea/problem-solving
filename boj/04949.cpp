// 04949번 균형잡힌 세상
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<bool> buffer; // (0), {1}
    string str;
    string::iterator iter;
    bool broken;

    while (true) {
        broken = false;
        while (!buffer.empty()) buffer.pop();

        getline(cin, str, '.');
        cin.ignore();
        if (str == "") {
            break;
        }
        for (iter=str.begin(); iter!=str.end(); iter++) {
            if (*iter == '(') {
                buffer.push(0);
            }
            else if (*iter == '['){
                buffer.push(1);
            }
            else if (*iter == ')') {
                if (buffer.empty()) {
                    cout << "no" << endl;
                    broken = true;
                    break;
                }

                if (buffer.top() == 0) {
                    buffer.pop();
                }
                else {
                    cout << "no" << endl;
                    broken = true;
                    break;
                }
            }
            else if (*iter == ']') {
                if (buffer.empty()) {
                    cout << "no" << endl;
                    broken = true;
                    break;
                }

                if (buffer.top() == 1) {
                    buffer.pop();
                }
                else {
                    cout << "no" << endl;
                    broken = true;
                    break;
                }
            }
        }
        if (!broken) {
            if (!buffer.empty()) {
                cout << "no" << endl;
            }
            else {
                cout << "yes" << endl;
            }
        }
    }
    return 0;
}