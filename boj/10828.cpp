// 10828번 스택
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    short N, i;
    string command;
    stack<int> s;
    int item;

    cin >> N;

    for (i=0; i<N; i++) {
        cin >> command;
        if (command == "push") {
            cin >> item;
            s.push(item);
        }
        else if (command == "pop") {
            if (s.empty()) {
                cout << "-1" << endl;
            }
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (command == "size") {
            cout << s.size() << endl;
        }
        else if (command == "empty") {
            cout << (s.empty() ? "1" : "0") << endl;
        }
        else if (command == "top") {
            if (s.empty()) {
                cout << "-1" << endl;
                continue;
            }
            cout << s.top() << endl;
        }
    }

    return 0;
}