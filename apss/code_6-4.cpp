#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    int n, m;
    int member1, member2;
    vector<int*> groups;
    
    cin >> c;
    for (int test_step = 0; test_step < c; test_step++) {
        groups.clear();
        cin >> n >> m;
        for (int group_step = 0; group_step < m; group_step++) {
            cin >> member1 >> member2;
            groups.push_back(new int[2] {member1, member2});
        }

        cout << n << ' ' << m << '\n';
        for (auto group: groups) {
            cout << group[0] << ' ' << group[1] << ' ';
        }
        cout << '\n';
    }

    return 0;
}